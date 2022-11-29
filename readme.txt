1. Eric Todd
2. [   45.368165] Thread function fs: 2b213d91, files: d9422d9b, nsproxy: 0ba1fda8
3. It appears that the module's working directory and root directory are both "/", because this was
    what out kernel module logged.
4. Module output:
    [ 2358.663487] Thread function fs: 1200d1e2, files: 42887208, nsproxy: bd5618c2
    [ 2358.663504] Thread function root: a09c52ff, pwd: a09c52ff
    [ 2358.663519] root_dentry and pwd_dentry are both /
    [ 2358.663533] d_iname: lost+found
    [ 2358.663548] d_iname: media
    [ 2358.663562] d_iname: mnt
    [ 2358.663576] d_iname: system-update
    [ 2358.663590] d_iname: gpgconf
    [ 2358.663603] d_iname: gpgv
    [ 2358.663617] d_iname: nonexistent
    [ 2358.663631] d_iname: net.conf
    [ 2358.663644] d_iname: abaton.conf
    [ 2358.663659] d_iname: agfafocus.conf
    [ 2358.663678] d_iname: apple.conf
    [ 2358.663694] d_iname: artec.conf
    [ 2358.663708] d_iname: artec_eplus48u.conf
    [ 2358.663722] d_iname: avision.conf
    [ 2358.663736] d_iname: bh.conf
    [ 2358.663749] d_iname: canon.conf
    [ 2358.663763] d_iname: canon630u.conf
    [ 2358.663777] d_iname: canon_dr.conf
    [ 2358.663791] d_iname: canon_lide70.conf
    [ 2358.663804] d_iname: cardscan.conf
    [ 2358.663818] d_iname: coolscan.conf
    [ 2358.663832] d_iname: coolscan3.conf
    [ 2358.663845] d_iname: dmc.conf
    [ 2358.663859] d_iname: epjitsu.conf
    [ 2358.663873] d_iname: epson2.conf
    [ 2358.663886] d_iname: epsonds.conf
    [ 2358.663900] d_iname: fujitsu.conf
    [ 2358.663914] d_iname: genesys.conf
    [ 2358.663927] d_iname: gt68xx.conf
    [ 2358.663941] d_iname: hp.conf
    [ 2358.663954] d_iname: hp3900.conf
    [ 2358.663968] d_iname: hp4200.conf
    [ 2358.663982] d_iname: hp5400.conf
    [ 2358.663995] d_iname: hpsj5s.conf
    [ 2358.664009] d_iname: hs2p.conf
    [ 2358.664022] d_iname: ibm.conf
    [ 2358.664035] d_iname: kodak.conf
    [ 2358.664049] d_iname: kodakaio.conf
    [ 2358.664063] d_iname: leo.conf
    [ 2358.664076] d_iname: lexmark.conf
    [ 2358.664090] d_iname: ma1509.conf
    [ 2358.664104] d_iname: magicolor.conf
    [ 2358.664117] d_iname: matsushita.conf
    [ 2358.664131] d_iname: microtek.conf
    [ 2358.664145] d_iname: microtek2.conf
    [ 2358.664158] d_iname: mustek.conf
    [ 2358.664172] d_iname: (null)
    [ 2358.664186] d_iname: mustek_usb.conf
    [ 2358.664199] d_iname: nec.conf
    [ 2358.664213] d_iname: pie.conf
    [ 2358.664226] d_iname: pieusb.conf
    [ 2358.664240] d_iname: pixma.conf
    [ 2358.664254] d_iname: plustek.conf
    [ 2358.664267] d_iname: ricoh.conf
    [ 2358.664281] d_iname: rts8891.conf
    [ 2358.664295] d_iname: s9036.conf
    [ 2358.664309] d_iname: sceptre.conf
    [ 2358.664322] d_iname: sharp.conf
    [ 2358.664336] d_iname: snapscan.conf
    [ 2358.664350] d_iname: sp15c.conf
    [ 2358.664363] d_iname: tamarack.conf
    [ 2358.664377] d_iname: teco1.conf
    [ 2358.664391] d_iname: teco2.conf
    [ 2358.664404] d_iname: teco3.conf
    [ 2358.664417] d_iname: u12.conf
    [ 2358.664431] d_iname: umax.conf
    [ 2358.664444] d_iname: umax1220u.conf
    [ 2358.664458] d_iname: xerox_mfp.conf
    [ 2358.664471] d_iname: dll.aliases
    [ 2358.664485] d_iname: dll.conf
    [ 2358.664499] d_iname: dll.d
    [ 2358.664512] d_iname: Library
    [ 2358.664526] d_iname: share
    [ 2358.664540] d_iname: devices
    [ 2358.664553] d_iname: devfs
    [ 2358.664567] d_iname: opt
    [ 2358.664581] d_iname: .flatpak-info
    [ 2358.664594] d_iname: lib64
    [ 2358.664608] d_iname: efi
    [ 2358.664621] d_iname: root
    [ 2358.664635] d_iname: forcequotacheck
    [ 2358.664649] d_iname: tmp
    [ 2358.664663] d_iname: srv
    [ 2358.664676] d_iname: home
    [ 2358.664689] d_iname: boot
    [ 2358.664703] d_iname: forcefsck
    [ 2358.664717] d_iname: fastboot
    [ 2358.664731] d_iname: sbin
    [ 2358.664745] d_iname: bin
    [ 2358.664758] d_iname: var
    [ 2358.664772] d_iname: selinux
    [ 2358.664785] d_iname: lib
    [ 2358.664799] d_iname: run
    [ 2358.664812] d_iname: sys
    [ 2358.664826] d_iname: proc
    [ 2358.664839] d_iname: etc
    [ 2358.664853] d_iname: usr
    [ 2358.664867] d_iname: dev
    [ 2360.593773] KTHREAD HAS BEEN ASKED TO STOP.
    This is different from the output of ls -l /:
    ls -l /
    total 69
    lrwxrwxrwx   1 root root     7 Apr  4  2022 bin -> usr/bin
    drwxr-xr-x   4 root root  5120 Dec 31  1969 boot
    drwxr-xr-x  17 root root  3820 Nov 27 17:37 dev
    drwxr-xr-x 119 root root 12288 Oct  4 21:56 etc
    drwxr-xr-x   3 root root  4096 Sep  1 10:06 home
    lrwxrwxrwx   1 root root     7 Apr  4  2022 lib -> usr/lib
    drwx------   2 root root 16384 Apr  4  2022 lost+found
    drwxr-xr-x   2 root root  4096 Apr  4  2022 media
    drwxr-xr-x   2 root root  4096 Apr  4  2022 mnt
    drwxr-xr-x   4 root root  4096 Apr  4  2022 opt
    dr-xr-xr-x 227 root root     0 Dec 31  1969 proc
    drwx------   6 root root  4096 Sep 14 21:59 root
    drwxr-xr-x  29 root root   860 Nov 27 18:25 run
    lrwxrwxrwx   1 root root     8 Apr  4  2022 sbin -> usr/sbin
    drwxr-xr-x   2 root root  4096 Apr  4  2022 srv
    dr-xr-xr-x  12 root root     0 Dec 31  1969 sys
    drwxrwxrwt  19 root root  4096 Nov 27 17:41 tmp
    drwxr-xr-x  11 root root  4096 Apr  4  2022 usr
    drwxr-xr-x  11 root root  4096 Apr  4  2022 var
5. Kernel module now logs:
    Thread function fs: 1200d1e2, files: 42887208, nsproxy: bd5618c2
    [ 2736.317745] Thread function root: a09c52ff, pwd: a09c52ff
    [ 2736.317763] root_dentry and pwd_dentry are both /
    [ 2736.317792] d_iname: opt
    [ 2736.317809] d_iname: root
    [ 2736.317825] d_iname: tmp
    [ 2736.317841] d_iname: home
    [ 2736.317858] d_iname: var
    [ 2736.317875] d_iname: etc
    [ 2736.317891] d_iname: usr
    [ 2740.624264] KTHREAD HAS BEEN ASKED TO STOP.
    This is still different from ls, missing directories such as media and sys. While these directories are
    not empty, they do not contain any further sub-directories.
6. 