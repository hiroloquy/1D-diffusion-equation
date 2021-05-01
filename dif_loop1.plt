#Loop processing 1 (Display of initial state) ----------------------------------------------
if ( exist ( "n" ) == 0 || n < 0 ) n = n0   #Initialize loop variable

plot '000.dat'using1:2with lines title sprintf("A", n) lc rgb "web-blue",¥
     '000.dat'using1:3with lines title sprintf("B", n) lc rgb "red"

n = n + dn                  # Increase loop variable
if ( n < n1 ) reread        # loop evaluation
undefine n                  # Delete loop variable