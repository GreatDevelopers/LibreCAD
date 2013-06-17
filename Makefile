#############################################################################
# Makefile for building: librecad
# Generated by qmake (2.01a) (Qt 4.8.1) on: Tue Jun 18 03:59:19 2013
# Project:  librecad.pro
# Template: subdirs
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile librecad.pro
#############################################################################

first: make_default
MAKEFILE      = Makefile
QMAKE         = /usr/bin/qmake-qt4
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
SUBTARGETS    =  \
		sub-libraries \
		sub-librecad \
		sub-plugins \
		sub-tools

libraries//$(MAKEFILE): 
	@$(CHK_DIR_EXISTS) libraries/ || $(MKDIR) libraries/ 
	cd libraries/ && $(QMAKE) /home/jasleen/Desktop/LibreCAD/libraries/libraries.pro -spec /usr/share/qt4/mkspecs/linux-g++ -o $(MAKEFILE)
sub-libraries-qmake_all:  FORCE
	@$(CHK_DIR_EXISTS) libraries/ || $(MKDIR) libraries/ 
	cd libraries/ && $(QMAKE) /home/jasleen/Desktop/LibreCAD/libraries/libraries.pro -spec /usr/share/qt4/mkspecs/linux-g++ -o $(MAKEFILE)
sub-libraries: libraries//$(MAKEFILE) FORCE
	cd libraries/ && $(MAKE) -f $(MAKEFILE)
sub-libraries-make_default-ordered: libraries//$(MAKEFILE) FORCE
	cd libraries/ && $(MAKE) -f $(MAKEFILE) 
sub-libraries-make_default: libraries//$(MAKEFILE) FORCE
	cd libraries/ && $(MAKE) -f $(MAKEFILE) 
sub-libraries-make_first-ordered: libraries//$(MAKEFILE) FORCE
	cd libraries/ && $(MAKE) -f $(MAKEFILE) first
sub-libraries-make_first: libraries//$(MAKEFILE) FORCE
	cd libraries/ && $(MAKE) -f $(MAKEFILE) first
sub-libraries-all-ordered: libraries//$(MAKEFILE) FORCE
	cd libraries/ && $(MAKE) -f $(MAKEFILE) all
sub-libraries-all: libraries//$(MAKEFILE) FORCE
	cd libraries/ && $(MAKE) -f $(MAKEFILE) all
sub-libraries-clean-ordered: libraries//$(MAKEFILE) FORCE
	cd libraries/ && $(MAKE) -f $(MAKEFILE) clean
sub-libraries-clean: libraries//$(MAKEFILE) FORCE
	cd libraries/ && $(MAKE) -f $(MAKEFILE) clean
sub-libraries-distclean-ordered: libraries//$(MAKEFILE) FORCE
	cd libraries/ && $(MAKE) -f $(MAKEFILE) distclean
sub-libraries-distclean: libraries//$(MAKEFILE) FORCE
	cd libraries/ && $(MAKE) -f $(MAKEFILE) distclean
sub-libraries-install_subtargets-ordered: libraries//$(MAKEFILE) FORCE
	cd libraries/ && $(MAKE) -f $(MAKEFILE) install
sub-libraries-install_subtargets: libraries//$(MAKEFILE) FORCE
	cd libraries/ && $(MAKE) -f $(MAKEFILE) install
sub-libraries-uninstall_subtargets-ordered: libraries//$(MAKEFILE) FORCE
	cd libraries/ && $(MAKE) -f $(MAKEFILE) uninstall
sub-libraries-uninstall_subtargets: libraries//$(MAKEFILE) FORCE
	cd libraries/ && $(MAKE) -f $(MAKEFILE) uninstall
librecad//$(MAKEFILE): 
	@$(CHK_DIR_EXISTS) librecad/ || $(MKDIR) librecad/ 
	cd librecad/ && $(QMAKE) /home/jasleen/Desktop/LibreCAD/librecad/librecad.pro -spec /usr/share/qt4/mkspecs/linux-g++ -o $(MAKEFILE)
sub-librecad-qmake_all:  FORCE
	@$(CHK_DIR_EXISTS) librecad/ || $(MKDIR) librecad/ 
	cd librecad/ && $(QMAKE) /home/jasleen/Desktop/LibreCAD/librecad/librecad.pro -spec /usr/share/qt4/mkspecs/linux-g++ -o $(MAKEFILE)
sub-librecad: librecad//$(MAKEFILE) FORCE
	cd librecad/ && $(MAKE) -f $(MAKEFILE)
sub-librecad-make_default-ordered: librecad//$(MAKEFILE) sub-libraries-make_default-ordered  FORCE
	cd librecad/ && $(MAKE) -f $(MAKEFILE) 
sub-librecad-make_default: librecad//$(MAKEFILE) FORCE
	cd librecad/ && $(MAKE) -f $(MAKEFILE) 
sub-librecad-make_first-ordered: librecad//$(MAKEFILE) sub-libraries-make_first-ordered  FORCE
	cd librecad/ && $(MAKE) -f $(MAKEFILE) first
sub-librecad-make_first: librecad//$(MAKEFILE) FORCE
	cd librecad/ && $(MAKE) -f $(MAKEFILE) first
sub-librecad-all-ordered: librecad//$(MAKEFILE) sub-libraries-all-ordered  FORCE
	cd librecad/ && $(MAKE) -f $(MAKEFILE) all
sub-librecad-all: librecad//$(MAKEFILE) FORCE
	cd librecad/ && $(MAKE) -f $(MAKEFILE) all
sub-librecad-clean-ordered: librecad//$(MAKEFILE) sub-libraries-clean-ordered  FORCE
	cd librecad/ && $(MAKE) -f $(MAKEFILE) clean
sub-librecad-clean: librecad//$(MAKEFILE) FORCE
	cd librecad/ && $(MAKE) -f $(MAKEFILE) clean
sub-librecad-distclean-ordered: librecad//$(MAKEFILE) sub-libraries-distclean-ordered  FORCE
	cd librecad/ && $(MAKE) -f $(MAKEFILE) distclean
sub-librecad-distclean: librecad//$(MAKEFILE) FORCE
	cd librecad/ && $(MAKE) -f $(MAKEFILE) distclean
sub-librecad-install_subtargets-ordered: librecad//$(MAKEFILE) sub-libraries-install_subtargets-ordered  FORCE
	cd librecad/ && $(MAKE) -f $(MAKEFILE) install
sub-librecad-install_subtargets: librecad//$(MAKEFILE) FORCE
	cd librecad/ && $(MAKE) -f $(MAKEFILE) install
sub-librecad-uninstall_subtargets-ordered: librecad//$(MAKEFILE) sub-libraries-uninstall_subtargets-ordered  FORCE
	cd librecad/ && $(MAKE) -f $(MAKEFILE) uninstall
sub-librecad-uninstall_subtargets: librecad//$(MAKEFILE) FORCE
	cd librecad/ && $(MAKE) -f $(MAKEFILE) uninstall
plugins//$(MAKEFILE): 
	@$(CHK_DIR_EXISTS) plugins/ || $(MKDIR) plugins/ 
	cd plugins/ && $(QMAKE) /home/jasleen/Desktop/LibreCAD/plugins/plugins.pro -spec /usr/share/qt4/mkspecs/linux-g++ -o $(MAKEFILE)
sub-plugins-qmake_all:  FORCE
	@$(CHK_DIR_EXISTS) plugins/ || $(MKDIR) plugins/ 
	cd plugins/ && $(QMAKE) /home/jasleen/Desktop/LibreCAD/plugins/plugins.pro -spec /usr/share/qt4/mkspecs/linux-g++ -o $(MAKEFILE)
sub-plugins: plugins//$(MAKEFILE) FORCE
	cd plugins/ && $(MAKE) -f $(MAKEFILE)
sub-plugins-make_default-ordered: plugins//$(MAKEFILE) sub-librecad-make_default-ordered  FORCE
	cd plugins/ && $(MAKE) -f $(MAKEFILE) 
sub-plugins-make_default: plugins//$(MAKEFILE) FORCE
	cd plugins/ && $(MAKE) -f $(MAKEFILE) 
sub-plugins-make_first-ordered: plugins//$(MAKEFILE) sub-librecad-make_first-ordered  FORCE
	cd plugins/ && $(MAKE) -f $(MAKEFILE) first
sub-plugins-make_first: plugins//$(MAKEFILE) FORCE
	cd plugins/ && $(MAKE) -f $(MAKEFILE) first
sub-plugins-all-ordered: plugins//$(MAKEFILE) sub-librecad-all-ordered  FORCE
	cd plugins/ && $(MAKE) -f $(MAKEFILE) all
sub-plugins-all: plugins//$(MAKEFILE) FORCE
	cd plugins/ && $(MAKE) -f $(MAKEFILE) all
sub-plugins-clean-ordered: plugins//$(MAKEFILE) sub-librecad-clean-ordered  FORCE
	cd plugins/ && $(MAKE) -f $(MAKEFILE) clean
sub-plugins-clean: plugins//$(MAKEFILE) FORCE
	cd plugins/ && $(MAKE) -f $(MAKEFILE) clean
sub-plugins-distclean-ordered: plugins//$(MAKEFILE) sub-librecad-distclean-ordered  FORCE
	cd plugins/ && $(MAKE) -f $(MAKEFILE) distclean
sub-plugins-distclean: plugins//$(MAKEFILE) FORCE
	cd plugins/ && $(MAKE) -f $(MAKEFILE) distclean
sub-plugins-install_subtargets-ordered: plugins//$(MAKEFILE) sub-librecad-install_subtargets-ordered  FORCE
	cd plugins/ && $(MAKE) -f $(MAKEFILE) install
sub-plugins-install_subtargets: plugins//$(MAKEFILE) FORCE
	cd plugins/ && $(MAKE) -f $(MAKEFILE) install
sub-plugins-uninstall_subtargets-ordered: plugins//$(MAKEFILE) sub-librecad-uninstall_subtargets-ordered  FORCE
	cd plugins/ && $(MAKE) -f $(MAKEFILE) uninstall
sub-plugins-uninstall_subtargets: plugins//$(MAKEFILE) FORCE
	cd plugins/ && $(MAKE) -f $(MAKEFILE) uninstall
tools//$(MAKEFILE): 
	@$(CHK_DIR_EXISTS) tools/ || $(MKDIR) tools/ 
	cd tools/ && $(QMAKE) /home/jasleen/Desktop/LibreCAD/tools/tools.pro -spec /usr/share/qt4/mkspecs/linux-g++ -o $(MAKEFILE)
sub-tools-qmake_all:  FORCE
	@$(CHK_DIR_EXISTS) tools/ || $(MKDIR) tools/ 
	cd tools/ && $(QMAKE) /home/jasleen/Desktop/LibreCAD/tools/tools.pro -spec /usr/share/qt4/mkspecs/linux-g++ -o $(MAKEFILE)
sub-tools: tools//$(MAKEFILE) FORCE
	cd tools/ && $(MAKE) -f $(MAKEFILE)
sub-tools-make_default-ordered: tools//$(MAKEFILE) sub-plugins-make_default-ordered  FORCE
	cd tools/ && $(MAKE) -f $(MAKEFILE) 
sub-tools-make_default: tools//$(MAKEFILE) FORCE
	cd tools/ && $(MAKE) -f $(MAKEFILE) 
sub-tools-make_first-ordered: tools//$(MAKEFILE) sub-plugins-make_first-ordered  FORCE
	cd tools/ && $(MAKE) -f $(MAKEFILE) first
sub-tools-make_first: tools//$(MAKEFILE) FORCE
	cd tools/ && $(MAKE) -f $(MAKEFILE) first
sub-tools-all-ordered: tools//$(MAKEFILE) sub-plugins-all-ordered  FORCE
	cd tools/ && $(MAKE) -f $(MAKEFILE) all
sub-tools-all: tools//$(MAKEFILE) FORCE
	cd tools/ && $(MAKE) -f $(MAKEFILE) all
sub-tools-clean-ordered: tools//$(MAKEFILE) sub-plugins-clean-ordered  FORCE
	cd tools/ && $(MAKE) -f $(MAKEFILE) clean
sub-tools-clean: tools//$(MAKEFILE) FORCE
	cd tools/ && $(MAKE) -f $(MAKEFILE) clean
sub-tools-distclean-ordered: tools//$(MAKEFILE) sub-plugins-distclean-ordered  FORCE
	cd tools/ && $(MAKE) -f $(MAKEFILE) distclean
sub-tools-distclean: tools//$(MAKEFILE) FORCE
	cd tools/ && $(MAKE) -f $(MAKEFILE) distclean
sub-tools-install_subtargets-ordered: tools//$(MAKEFILE) sub-plugins-install_subtargets-ordered  FORCE
	cd tools/ && $(MAKE) -f $(MAKEFILE) install
sub-tools-install_subtargets: tools//$(MAKEFILE) FORCE
	cd tools/ && $(MAKE) -f $(MAKEFILE) install
sub-tools-uninstall_subtargets-ordered: tools//$(MAKEFILE) sub-plugins-uninstall_subtargets-ordered  FORCE
	cd tools/ && $(MAKE) -f $(MAKEFILE) uninstall
sub-tools-uninstall_subtargets: tools//$(MAKEFILE) FORCE
	cd tools/ && $(MAKE) -f $(MAKEFILE) uninstall

Makefile: librecad.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile librecad.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
qmake: qmake_all FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile librecad.pro

qmake_all: sub-libraries-qmake_all sub-librecad-qmake_all sub-plugins-qmake_all sub-tools-qmake_all FORCE

make_default: sub-libraries-make_default-ordered sub-librecad-make_default-ordered sub-plugins-make_default-ordered sub-tools-make_default-ordered FORCE
make_first: sub-libraries-make_first-ordered sub-librecad-make_first-ordered sub-plugins-make_first-ordered sub-tools-make_first-ordered FORCE
all: sub-libraries-all-ordered sub-librecad-all-ordered sub-plugins-all-ordered sub-tools-all-ordered FORCE
clean: sub-libraries-clean-ordered sub-librecad-clean-ordered sub-plugins-clean-ordered sub-tools-clean-ordered FORCE
distclean: sub-libraries-distclean-ordered sub-librecad-distclean-ordered sub-plugins-distclean-ordered sub-tools-distclean-ordered FORCE
	-$(DEL_FILE) Makefile
install_subtargets: sub-libraries-install_subtargets-ordered sub-librecad-install_subtargets-ordered sub-plugins-install_subtargets-ordered sub-tools-install_subtargets-ordered FORCE
uninstall_subtargets: sub-libraries-uninstall_subtargets-ordered sub-librecad-uninstall_subtargets-ordered sub-plugins-uninstall_subtargets-ordered sub-tools-uninstall_subtargets-ordered FORCE

sub-libraries-check_ordered: libraries/$(MAKEFILE)
	cd libraries/ && $(MAKE) -f $(MAKEFILE) check
sub-librecad-check_ordered: librecad/$(MAKEFILE) sub-libraries-check_ordered 
	cd librecad/ && $(MAKE) -f $(MAKEFILE) check
sub-plugins-check_ordered: plugins/$(MAKEFILE) sub-librecad-check_ordered 
	cd plugins/ && $(MAKE) -f $(MAKEFILE) check
sub-tools-check_ordered: tools/$(MAKEFILE) sub-plugins-check_ordered 
	cd tools/ && $(MAKE) -f $(MAKEFILE) check
check: sub-libraries-check_ordered sub-librecad-check_ordered sub-plugins-check_ordered sub-tools-check_ordered

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all
install: install_subtargets  FORCE

uninstall:  uninstall_subtargets FORCE

FORCE:

