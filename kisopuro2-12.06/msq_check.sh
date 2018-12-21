#!/bin/sh
#
# Check Magic Square Program
# Filename: check.sh
# Usage: ./check.sh ./a.out
#

echo ========================= ./a.out

echo "##### Magic #####"
echo "8 3 4 1 5 9 6 7 2" | ./a.out
echo
echo "##### NotMagic #####"
# 最右、最上がおかしい
echo "9 8 4 5 1 6 7 3 2" | ./a.out
# 最左、最上がおかしい
echo "9 1 5 7 2 6 8 3 4" | ./a.out
# 左下から右上の斜めがおかしい
echo "5 3 7 1 8 6 9 4 2" | ./a.out
# 最右、最下段がおかしい
echo "8 7 3 4 9 5 6 2 1" | ./a.out
# 最下段がおかしい
echo "6 4 5 7 8 9 2 3 1" | ./a.out

echo
