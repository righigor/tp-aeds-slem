#ifndef LOCAL_H
#define LOCAL_H

class Local {
    private:
        char nome[100];
        int coordenadaX;
        int coordenadaY;
    public: 
        Local(char * nome, int x, int y);

        const char* getNome() const;
        void setNome(char * nome);

        int getCoordenadaX() const;
        int getCoordenadaY() const;

        void getLocal() const;
};

#endif