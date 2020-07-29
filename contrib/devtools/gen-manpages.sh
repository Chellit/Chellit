#!/bin/sh

TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
SRCDIR=${SRCDIR:-$TOPDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

CHELLITD=${CHELLITD:-$SRCDIR/chellitd}
CHELLITCLI=${CHELLITCLI:-$SRCDIR/chellit-cli}
CHELLITTX=${CHELLITTX:-$SRCDIR/chellit-tx}
CHELLITQT=${CHELLITQT:-$SRCDIR/qt/chellit-qt}

[ ! -x $CHELLITD ] && echo "$CHELLITD not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
CHEVER=($($CHELLITCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for chellitd if --version-string is not set,
# but has different outcomes for chellit-qt and chellit-cli.
echo "[COPYRIGHT]" > footer.h2m
$CHELLITD --version | sed -n '1!p' >> footer.h2m

for cmd in $CHELLITD $CHELLITCLI $CHELLITTX $CHELLITQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${CHEVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${CHEVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
