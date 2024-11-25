echo "Enter file name: "
read FILENAME

gcc-14 -Wall -Wextra $FILENAME.c -o $FILENAME

./$FILENAME

rm $FILENAME
