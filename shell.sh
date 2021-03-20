#!/bin/bash
# Bash Menu Script Example

HEIGHT=15
WIDTH=40
CHOICE_HEIGHT=4

while [ 1 ]; do
  BACKTITLE="Backtitle here"
  TITLE="GRAFOS"
  MENU="Choose one of the following options:"

  OPTIONS=(1 "Option 1"
    2 "Option 2"
    3 "Option 3"
    4 "Option 4")

  CHOICE=$(dialog --clear \
    --backtitle "$BACKTITLE" \
    --title "$TITLE" \
    --menu "$MENU" \
    $HEIGHT $WIDTH $CHOICE_HEIGHT \
    "${OPTIONS[@]}" \
    2>&1 >/dev/tty)

  clear
  case $CHOICE in
  1)
    cls
    echo "You chose Option 1"
    read -p "Pressione enter para sair"
    exit 1
    ;;

  2)
    echo "You chose Option 2"
    exit 2
    ;;
  3)
    echo "You chose Option 3"
    exit 3
    ;;
  4)
    exit 4
    ;;
  esac
done
