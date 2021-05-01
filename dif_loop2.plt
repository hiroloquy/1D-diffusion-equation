#Loop processing 2 (output animated GIF from n0 to n2) ----------------------------------------
if ( exist ( "n" ) == 0 || n < 0 ) n = n0 #Initialize loop variable

filename = sprintf("%03d.dat", n)
plot filename using1:2with lines title sprintf("A", n) lc rgb "web-blue",¥
     filename using1:3with lines title sprintf("B", n) lc rgb "red"

n = n + dn                  # Increase loop variable
if ( n < n2 ) reread        # loop evaluation
undefine n                  # Delete loop variable