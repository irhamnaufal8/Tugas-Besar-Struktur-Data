//
//  main.cpp
//  NtoN
//
//  Created by Garry on 31/12/21.
//

#include "NtoN.hpp"

int main(){
    Listmahasiswa L;
//    adr_mahasiswa D = nullptr;
//    adr_prestasi P = nullptr;
    int pilihan = 0;
    char is_continue;

    createList(L);

    pilihan = selectmenu();

    while(pilihan != 0){
            switch(pilihan){
            case 1 :
                menambahkan_mahasiswa(L);
                break;
            case 2 :
                showmahasiswa(L);
                break;
            case 3 :
                delete_parent(L);
                break;
            case 4 :
                menambahkan_prestasi(L);
                break;
            case 5 :
                showprestasi(L);
                break;
            case 6 :
                menghapusprestasi(L);
                break;
            case 7 :
                delate_relation(L);
                break;
            case 8 :
                update_some(L);
                break;
            case 9 :
                count_matakuliah(L);
                break;
            default :
                cout<<"Pilihan Tidak Ditemukan"<<endl;
                break;
        }
          label_continue :
            cout<<"Lanjutkan?(Y/N) : ";
            cin>>is_continue;
            if (is_continue == 'Y' || is_continue == 'y'){
                 pilihan = selectmenu();
            }else if (is_continue == 'N' || is_continue == 'n'){
                break;
            }else{
                goto label_continue;

            }
         }
          cout<<"- - - Program Berakhir - - -";

    return 0;
}
