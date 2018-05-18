func main()
    var c1, c2, c3, c4, tmp : char
    var b : bool
    c1 = 'a';
    c2 = 'z';
    c3 = 'A';
    c4 = 'Z';
    tmp = '7';
    
    while tmp!='a' do
        read tmp;
        if tmp >= 'a' and tmp <= 'z' then
            write "MINUS";
        endif
        if tmp >= 'A' and tmp <= 'Z' then
            write "MAYUS";
        endif
        write "\n";
    endwhile
    write tmp;
    write '\n';
    tmp = c4;
    write tmp;
    write '\n';
    write '9';
    write '\n';
endfunc
