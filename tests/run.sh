#echo "making libft..."
make -C ../libft/
#echo "done making libft"

#echo "making libftprintf..."
make -C ..
#echo "done making libftprintf"

rm "tester_mine"
rm -r "tester_mine.dSYM"

# testing program name; definition file
compile_with_define () {
    cat $2 main.c > defined_main.c
    # -Wall -Werror -Wextra
    gcc -g  -o $1 ../libftprintf.a defined_main.c
    if [ ! -f $1 ]; then
	echo "FAILED COMPILATION: " $1
	exit
    fi
    #rm defined_main.c
    echo "done making" $1
}

# make the two executable files
compile_with_define tester_mine define_mine.c
compile_with_define tester_theirs define_theirs.c

# actual testing
echo "starting tests==========================================================="
./tester_mine > mine
echo "done testing mine========================================================"
./tester_theirs > theirs
echo "done testing theirs======================================================"

# diff the output files
echo "DIFF====================================================================="
diff mine theirs
echo "END======================================================================"

# remove testing program and defined main
#rm "tester_mine"
#rm -r "tester_mine.dSYM"
rm "tester_theirs"
rm -r "tester_theirs.dSYM"
rm "mine"
rm "theirs"

echo "done with program"
