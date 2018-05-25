func reverse(a1: array[10] of char,
                  a2: array[10] of char): char
    var i: int
    var c: char
    i = 0;
    while i < 10 do
        a2[i] = a1[9-i];
	    i = i+1;
    endwhile
    return 'B';
endfunc

func main()
    var v1, v2: array[10] of char
    var i : int

    
    v1[0] = 'a';
    v1[1] = 'b';
    v1[2] = 'c';
    v1[3] = 'd';
    v1[4] = 'e';
    v1[5] = 'f';
    v1[6] = 'g';
    v1[7] = 'h';
    v1[8] = 'i';
    v1[9] = '\n';
    
    write v1[7];
    write v1[9];
    
    write reverse(v1, v2);
    write '\n';
    
    i = 0;
    while i < 10 do
        write v2[i];
        write '\n';
	    i = i+1;
    endwhile
   
endfunc

