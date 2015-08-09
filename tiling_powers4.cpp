void pre()
{
     poww4[0] = 1;
     for ( int i = 1; i <= 3; i++ ) poww4[i] = poww4[i-1]*4;
     for ( int i = 0; i < poww4[3]; i++ ) {
         for ( int j = 0; j < 3; j++ ) {
             get[i][j] = (i/poww4[j])%4;
             for ( int k = 0; k <= 3; k++ ) {
                 rep[i][j][k] = i + (k-get[i][j])*poww4[j];                  
             }
         }
     }
     return;
}
