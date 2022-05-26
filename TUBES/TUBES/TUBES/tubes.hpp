//
//  tubes.hpp
//  TUBES
//
//  Created by Garry on 26/12/21.
//

#ifndef tubes_hpp
#define tubes_hpp

#include <iostream>
#define next(P) (P) -> next
#define nextprestasi(P) (P) -> nextprestasi
#define first(P) ((P).first)
#define info(P) (P) -> info
#define input(P) ((P).input)
#define nil NULL

using namespace std;

typedef struct elm_prestasi *adr_prestasi;
typedef struct elm_mahasiswa *adr_mahasiswa;

struct mahasiswa {
    string nama;
    string nim;
};

struct elm_mahasiswa {
    mahasiswa info;
    adr_mahasiswa next;
    adr_prestasi nextprestasi;
};

struct prestasi {
    string prestasi;
    int juara;
};

struct elm_prestasi {
    prestasi info;
    adr_prestasi next;
};

struct mll {
    adr_mahasiswa first;
};

void create_list(mll &L);
void menambahkan_mahasiswa(mll &list_mahasiswa);
void insert_parent(mll &list_mahasiswa, adr_mahasiswa m);
void delete_parent(mll &list_mahasiswa);
void show_parent(mll list_mahasiswa);
adr_mahasiswa find_parent(mll &list_mahasiswa, mahasiswa input);
void insert_child_of_parent(mll &list_mahasiswa);
void delete_child_of_parent(mll &list_mahasiswa);
void show_child_of_parent(mll list_mahasiswa);
adr_prestasi find_child_of_parent(mll &list_mahasiswa, prestasi input);
adr_mahasiswa new_elm_mahasiswa(mahasiswa x);
adr_prestasi new_elm_prestasi(prestasi x);
void delete_after_parent(mll &list_mahasiswa, adr_mahasiswa prec, adr_mahasiswa &m);
void delete_first_parent(mll &list_mahasiswa, adr_mahasiswa &m);
void delete_last_parent(mll &list_mahasiswa, adr_mahasiswa &m);
void delete_after_child(mll &list_mahasiswa, adr_prestasi prec, adr_prestasi &p, adr_mahasiswa m);
void delete_first_child(mll &list_mahasiswa, adr_prestasi p, adr_mahasiswa m);
void delete_last_child(mll &list_mahasiswa, adr_prestasi p, adr_mahasiswa m);
void jumlah_juara(mll list_mahasiswa);
void delate_relation(mll &list_mahasiswa);
void update_some(mll &list_mahasiswa);
void count_prestasi(mll &list_mahasiswa);
int selectmenu();





#endif /* tubes_hpp */
