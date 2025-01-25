tests=`sed '1q;d' 1.in`
for i in $(seq 2 $(($tests+1)));
do
	input=`sed "$i q;d" 1.in`
	result=`./$1 $input`
	com=`sed "$i q;d" test1.in`
	exp_result=`bash -c "$com"` 
	if [[ "$result" == "$exp_result" ]]; then : ; else echo 0; exit 0; fi;
done
echo 1
