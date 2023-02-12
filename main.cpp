#include "mainwindow.h"
#include "includes.h"
#include <QApplication>
using namespace std;


int main(int argc, char *argv[])
{

    ifstream namesfile("C:/Users/Public/names.txt");
    ifstream adjectives("C:/Users/Public/adj.txt");
    if(!namesfile)
    {
        system("powershell $ProgressPreference = \'SilentlyContinue\' ; curl \"https://raw.githubusercontent.com/jeanphorn/wordlist/master/usernames.txt -O C:/Users/Public/names.txt"); // Download the Names file
    }
    if(!adjectives)
    {
        system("powershell $ProgressPreference = \'SilentlyContinue\' ; curl \"https://gist.githubusercontent.com/hugsy/8910dc78d208e40de42deb29e62df913/raw/eec99c5597a73f6a9240cab26965a8609fa0f6ea/english-adjectives.txt -O C:/Users/Public/adj.txt"); // Download the ADJ list
    }
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}


HCRYPTPROV prov;
int random() {
    if (prov == NULL)
        if (!CryptAcquireContext(&prov, NULL, NULL, PROV_RSA_FULL, CRYPT_SILENT | CRYPT_VERIFYCONTEXT))
            ExitProcess(1);

    int out;
    CryptGenRandom(prov, sizeof(out), (BYTE*)(&out));
    return out & 0x7fffffff;
}
