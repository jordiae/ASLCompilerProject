func main()
    var n1, n2, tmp : int
    n1 = 0;
    n2 = 0;
    while n1!=500 do
        read n1;
        read n2;
        tmp = n1 % n2;
        write tmp;
        write "\n";
    endwhile
endfunc
