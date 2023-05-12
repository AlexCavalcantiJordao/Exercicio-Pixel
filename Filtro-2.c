#include <Windows.h> // Para a janela de selecionar o arquivo
#include <string>
#include <cstring>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

sf::Texture LoadTexture(void)
{
    OPENFILENAME ofn;

    ZeroMemory(&ofn, sizeof(ofn));

    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = 0;
    ofn.lpstrDefExt = 0;
    ofn.lpstrFile = new TCHAR[512];
    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = 512;
    ofn.lpstrFilter = NULL;
    ofn.nFilterIndex = 0;
    ofn.lpstrInitialDir = NULL;
    ofn.lpstrTitle = L"Selecione uma Imagem";
    ofn.Flags = 0;

    GetOpenFileName(&ofn);

    // Converte para std::string.
    std::wstring wstr = ofn.lpstrFile;
    std::string str(wstr.begin(), wstr.end());

    // Armazenar� a imagem.
    sf::Texture texture;

    // Verifica se o arquivo � v�lido e se foi poss�vel carregar.
    if (!texture.loadFromFile(str))
    {
        MessageBox(NULL, L"Imagem inv�lida!", L"Erro", MB_OK);
    }

    return texture;
}
