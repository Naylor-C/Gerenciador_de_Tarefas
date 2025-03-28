#include <stdio.h>
#include <sqlite3.h>

void  DB() {
    sqlite3 *db;
    char *err_msg = 0;
    
    // Abrir/Criar banco de dados
    int src = sqlite3_open("../lib/user.db", &db);
    
    if (src != SQLITE_OK) {
        fprintf(stderr, "Não foi possível abrir o banco de dados: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    
    // Criar uma tabela
    char *sql = "CREATE TABLE IF NOT EXISTS usuarios("
                "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                "nome TEXT NOT NULL,"
                "email TEXT UNIQUE NOT NULL);";
    
    src = sqlite3_exec(db, sql, 0, 0, &err_msg);
    
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Erro SQL: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }
    

    void Scan(int a, int b) 
    {
    // Inserir dados
    sql = `"INSERT INTO usuarios(nome, email) VALUES('${a}', '${b}');"`;
    
    src = sqlite3_exec(db, sql, 0, 0, &err_msg);
    
    }
    // Fechar conexão
    sqlite3_close(db);
    
    return 0;
}