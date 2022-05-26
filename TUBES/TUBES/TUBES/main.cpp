//
//  main.cpp
//  TUBES
//
//  Created by Garry on 26/12/21.
//

#include "tubes.hpp"

int main(){
    mll l;
    int pilihan = 0;
    char is_continue;
    
    create_list(l);
    
    pilihan = selectmenu();

    while(pilihan != 0){
            switch(pilihan){
            case 1 :
                menambahkan_mahasiswa(l);
                break;
            case 2 :
                show_parent(l);
                break;
            case 3 :
                delete_parent(l);
                break;
            case 4 :
                insert_child_of_parent(l);
                break;
            case 5 :
                show_child_of_parent(l);
                break;
            case 6 :
                delete_child_of_parent(l);
                break;
            case 7 :
                delate_relation(l);
                break;
            case 8 :
                update_some(l);
                break;
            case 9 :
                count_prestasi(l);
                break;
            default :
                cout << "Pilihan Tidak Ditemukan" << endl;
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
          cout <<"- - - - Program Berakhir - - - -" << endl;
    
    return 0;
}
