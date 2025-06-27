#ifndef LOCAL_H
#define LOCAL_H

class Local {
    private:
        int localId;
        char nome[100];
        int coordenadaX;
        int coordenadaY;
    public: 
        Local(const char * nome, int x, int y);

        int getlocalId() const;
        void setLocalId(int id);

        const char* getNome() const;
        void setNome(const char * nome);

        int getCoordenadaX() const;
        int getCoordenadaY() const;
        void setCoordenadaX(int X);
        void setCoordenadaY(int Y);
        
        void getLocal() const;
};

#endif