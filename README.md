# reinforcement\_learning\_rocket\_league

Ne pas omettre de lancer le programme en passant par `/usr/bin/sudo` !  
`apropos --section <man_page> '.'`  

## Etape 1
Realisation d'un overlay affichant une mini-map pendant la partie  
_Objectif_ : etre capable de lire et identifier les donnees de jeu dans la memoire RAM  

## Etape 2
Realisation d'un programme permettant de mapper les controles d'une manette de jeu  
_Objectif_ : etre capable d'emuler une manette detectable par les autres programmes  

## Etape 3
Realisation d'agents s'entrainant dans le cadre de parties en ecran partage  
_Objectif_ : boire un cafe devant l'ordinateur les jambes croisees sur la table en s'amusant du niveau pitoyable des agents s'affrontant  

## Sources d'inspiration :

[NexusMod - Overlay Monster Hunter World](https://www.nexusmods.com/monsterhunterworld/mods/142)  
[GitHub - AlphaConsole (Rocket League)](https://github.com/AlphaConsole/AlphaConsoleElectron)  
[AlternativeTo - ControlMK](https://alternativeto.net/software/controlmk/)  

### Concernant la lecture dans la memoire RAM

[GNU](https://www.gnu.org/)  
[The Free Software Directory - libc](https://directory.fsf.org/wiki/Libc)  
[The GNU C Library](https://www.gnu.org/software/libc/)  
[Sourceware - libc](https://sourceware.org/git/?p=glibc.git;a=tree)  
[Sourceware - libc - features.h (\_GNU\_SOURCE)](https://sourceware.org/git/?p=glibc.git;a=blob;f=include/features.h;hb=HEAD)  
[Sourceware - libc - uio.h](https://sourceware.org/git/?p=glibc.git;a=blob;f=misc/sys/uio.h;hb=HEAD)  
[Sourceware - libc - uio-ext.h](https://sourceware.org/git/?p=glibc.git;a=blob;f=sysdeps/unix/sysv/linux/bits/uio-ext.h;hb=HEAD)  
[Sourceware - libc - struct\_iovec.h](https://sourceware.org/git/?p=glibc.git;a=blob;f=misc/bits/types/struct_iovec.h;hb=HEAD)  
[Sourceware - libc - process\_vm\_readv.c](https://sourceware.org/git/?p=glibc.git;a=blob;f=sysdeps/unix/sysv/linux/process_vm_readv.c;hb=HEAD)  

### Concernant l'affichage d'un overlay devant un jeu en ecran fenetre

[GitHub 42Paris - minilibx-linux/mlx\_int.h](https://github.com/42Paris/minilibx-linux/blob/master/mlx_int.h)  
[GitHub HippopoStar - branche\_graphique/notes\_perso.txt](https://github.com/HippopoStar/branche_graphique/blob/master/notes_perso.txt)  
[Wikipedia - X Window System](https://fr.wikipedia.org/wiki/X_Window_System)  

[X.Org](https://www.x.org/)  
[GTK](https://gtk.org/)  
[OpenGL](https://www.opengl.org/)  

### Concernant le mappage des entrees de la manette de jeu

[Wikipedia - Pile graphique Linux](https://fr.wikipedia.org/wiki/Pile_graphique_Linux)  
[Wikipedia - Fichier : Wayland\_display\_server\_protocol.svg](https://fr.wikipedia.org/w/index.php?title=Fichier:Wayland_display_server_protocol.svg&lang=fr)  
`/usr/bin/man 4 libinput`  
[Wayland - libinput API Documentation](https://wayland.freedesktop.org/libinput/doc/latest/api/)  
[Wikipedia - Noyau Linux](https://fr.wikipedia.org/wiki/Noyau_Linux)  
[GitHub Torvalds - linux/Documentation/input/gamepad.rst](https://github.com/torvalds/linux/blob/master/Documentation/input/gamepad.rst)  

