#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/fs_struct.h>
#include <linux/dcache.h>
#include <linux/fdtable.h>
#include <linux/fs.h>

static struct task_struct* task;

static unsigned int pid = 0;
module_param(pid, uint, 0644);

static int threadfunction(void* data) {
  struct task_struct* this_thread = current;
  struct fs_struct* fs = this_thread->fs;
  struct path root = fs->root;
  struct path pwd = fs->pwd;
  struct dentry* root_dentry = root.dentry;
  struct dentry* pwd_dentry = pwd.dentry;
  struct list_head* pos;
  struct list_head* head;
  printk(KERN_INFO "Thread function fs: %p, files: %p, nsproxy: %p\n" , this_thread->fs, this_thread->files, this_thread->nsproxy);
  printk(KERN_INFO "Thread function root: %p, pwd: %p\n", root_dentry, pwd_dentry);
  if(root_dentry != pwd_dentry) {
    printk(KERN_INFO "root_dentry d_iname: %s, pwd_dentry d_iname: %s\n", root_dentry->d_iname, pwd_dentry->d_iname);
  } else {
    printk(KERN_INFO "root_dentry and pwd_dentry are both %s\n", root_dentry->d_iname);
  }

  head = &root_dentry->d_subdirs;
  list_for_each(pos, head) {
    struct dentry* dentry = list_entry(pos, struct dentry, d_child);
    if(!list_empty(&dentry->d_subdirs)) {
      printk(KERN_INFO "d_iname: %s\n", dentry->d_iname);
    }
  }

  while (!kthread_should_stop()) {
    schedule();
  }
  return 0;
}

static int threadFunctionPid(void* data) {
  printk(KERN_INFO "threadFunctionPid called, pid=%d\n", pid);
  struct pid* pid_struct = find_vpid(pid);
  printk(KERN_INFO "pid_struct: %p\n", pid_struct);
  struct task_struct* process;
  struct files_struct* files;
  struct file* file;
  loff_t offset = 0;
  const char* output = "Hello World!";
  const struct file_operations* fops;
  if(!pid_struct) {
    printk(KERN_INFO "Could not find pid %d\n", pid);
    return 0;
  }
  process = get_pid_task(pid_struct, PIDTYPE_PID);
  printk(KERN_INFO "process: %p\n", process);
  if(!process) {
    printk(KERN_INFO "Could not find task for pid %d\n", pid);
    return 0;
  }
  files = process->files;
  printk(KERN_INFO "files: %p\n", files);
  if(!files) {
    printk(KERN_INFO "Could not find files for pid %d\n", pid);
    return 0;
  }
  file = fcheck_files(files, 2);
  printk(KERN_INFO "file: %p\n", file);
  if(!file) {
    printk(KERN_INFO "Could not find file for pid %d\n", pid);
    return 0;
  }
  fops = file->f_op;
  printk(KERN_INFO "fops: %p\n", fops);
  if(!fops) {
    printk(KERN_INFO "Could not find fops for pid %d\n", pid);
    return 0;
  }
  printk(KERN_INFO "fops->write: %p\n", fops->write);
  printk(KERN_INFO "fops->read: %p\n", fops->read);
  printk(KERN_INFO "fops->read_iter: %p\n", fops->read_iter);
  printk(KERN_INFO "fops->write_iter: %p\n", fops->write_iter);
  (*(fops->write))(file, output, strlen(output), &offset);

  while(!kthread_should_stop()) {
    schedule();
  }
  return 0;
}

/* init function - logs that initialization happened, returns success */
static int kthread_init(void) {
  printk(KERN_DEBUG "KTHREAD IS BEING LOADED. \n");
  if(pid) {
    task = kthread_create(threadFunctionPid, NULL, "Test thread for pid %d", pid);
  } else {
    task = kthread_create(threadfunction, NULL, "Test thread");
  }
  kthread_bind(task, 0);
  wake_up_process(task);
  return 0;
}

/* exit function - logs that the module is being removed */
static void kthread_exit(void) {
  kthread_stop(task);
  printk(KERN_DEBUG "KTHREAD HAS BEEN ASKED TO STOP. \n");
}

module_init(kthread_init);
module_exit(kthread_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Eric Todd");
MODULE_DESCRIPTION("KThread module");
