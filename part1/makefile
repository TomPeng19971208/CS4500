docker:
	echo "Nothing to build, as we use Python. All good."
test:
	chmod 777 sorer
	./sorer -f "data.sor" -from 0 -len 100 -print_col_type 0
	./sorer -f "data.sor" -from 0 -len 100 -print_col_type 2
	./sorer -f "data.sor" -from 0 -len 100 -is_missing_idx 2 0
	./sorer -f "data.sor" -from 0 -len 100 -is_missing_idx 2 1
	./sorer -f "data.sor" -from 0 -len 100 -is_missing_idx 2 2
	./sorer -f "data.sor" -from 0 -len 100 -print_col_idx 2 0
	./sorer -f "data.sor" -from 5 -len 100 -print_col_idx 1 0
