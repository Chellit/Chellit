
Debian
====================
This directory contains files used to package chellitd/chellit-qt
for Debian-based Linux systems. If you compile chellitd/chellit-qt yourself, there are some useful files here.

## chellit: URI support ##


chellit-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install chellit-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your chellit-qt binary to `/usr/bin`
and the `../../share/pixmaps/chellit128.png` to `/usr/share/pixmaps`

chellit-qt.protocol (KDE)

