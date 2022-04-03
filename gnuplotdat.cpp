#include<iostream>

using namespace std;

int main(void){
    int x;
    int y;
    FILE *fp = nullptr;
    FILE *gnupipe = nullptr;
    char *GnuCommands [] ={"set title \"Demo\"","plot 'data.tmp'"};

    fp  = fopen ("data.tmp","w");
    gnupipe = _popen("gnuplot -persistent","w");

    for (int i =0;i<11;i++){
        fprintf(fp,"%d %d\n",x,y);

         x+=1;
         y+=1;
    }

    for (int i =0;i<2;i++){
        fprintf(gnupipe,"%s\n",GnuCommands[i]);
    }
    return 0;
}