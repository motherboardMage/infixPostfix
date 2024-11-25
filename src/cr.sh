# only for compiling, running and removing 
# result of test code in one go since I'm too
# lazy to do it manually

echo "Enter file name: "
read FILENAME

gcc-14 -Wall -Wextra $FILENAME.c -o $FILENAME

./$FILENAME

rm $FILENAME
