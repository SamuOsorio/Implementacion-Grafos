#ifndef RELACION_H
#define RELACION_H

#include <string>

template<typename T>

class Relacion{
public:
    std::string source;
    std::string target;
    std::string type;
    int peso;
    int libro;
    
private:
	
    Relacion(const std::string& source, const std::string& target, const std::string& type, int peso, int libro);
    
    std::string getSource() const;
    std::string getTarger() const;
	std::string getType() const;
	int getPeso() const;
    int getLibro() const;
    
	void setSource(std::string source);
    void setTarger(std::string target);
	void setType(std::string type);
	void setPeso(int peso);
    void setLibro(int libro);
};

#endif