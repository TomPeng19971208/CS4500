This data adapter transforms a given SOR file into a columnar represented data frame

A SOR file is a sequence of rows, each row contains data surrounded by <>
In general, we assume that there are no empty rows in the file. If empty rows exist, they will be indexed. If
the first 500 lines are empty, this adapter is not able to infer columns' type. So be mindful of that, and make sure
there are no empty rows in the file, empty rows might lead to unexpected behaviors. 

Supported interactions are:
-f  str     // path to SoR file to be read (required)
-from uint  // starting position in the file (in bytes) (required)
-len uint   // number of bytes to read (required)
-print_col_type uint  // print the type of a column: BOOL, INT, FLOAT, STRING  (optional)
-print_col_idx uint uint  // the first argument is the column, the second is the offset  (optional)
-is_missing_idx uint uint // is there a missing in the specified column offset  (optional)

Types:
We support 5 data type: Int, Bool, Float, String, Undefined. If none of the cells in a column contain a valid data, 
the program interpret the column's type as Undefined. 

WorkFlow:
1) If a file's schema has already been inferred, the program will load it from disk. Format of the schema file on disk will be specified later. 
    - Notice: we associate schema file with an input file using the input file's name. Please make sure if an input file is changed, 
              the associated schema file should be deleted. 
2) Open the file, read until the 500th line is reached. Those lines will be used to infer the file's schema. 
    - Specific rules can be found http://janvitek.org/events/NEU/4500/s20/projects2.html#
    - Notice: if an integer column only contain 0/1 in the first 500 rows, that column will be identified as Bool. After 500th line, 
              values that is not 0/1 in that column will be ignored.
4) Store the schema onto disk if necessary. The file only contain 1 line of integers seperated by white spaces, each integer represents a data type 
3) From "-from", read "-len" byte from the input file into a buffer. If the file is read partially, discard the first/last line if necessary
4) Columnize the data in that buffer, ignore values that fail to match with the inferred schema
5) perform operations 
    -print_col_type uint  (if the given )
    -print_col_idx uint uint
    -is_missing_idx uint uint
    -Notice: segmented rows will be ignored, and these rows will not be indexed
    