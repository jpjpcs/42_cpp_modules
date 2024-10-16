/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:13:08 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/12 11:10:38 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
1 - Explicação da fórmula usada na função area:
    static float area(const Point p1, const Point p2, const Point p3) 
    {
        // Fórmula determinante 2D para calcular a área
        return abs((p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat()) +
                    p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat()) +
                    p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat())) / 2);
    }
    1.1. - A fórmula clássica para calcular a área de um triângulo é:
        Área = base × altura / 2
        Esta fórmula é particularmente simples quando se conhece a base e a altura do triângulo. 
        Contudo, no caso de triângulos definidos por três pontos em um plano, a base e a altura 
        podem não ser imediatamente óbvias. Neste caso, usamos uma fórmula mais geral, 
        baseada em coordenadas, para calcular a área do triângulo a partir de seus vértices.
    1.2. - A função que estás a usar para calcular a área do triângulo usa uma fórmula derivada do 
        determinante 2D para encontrar a área de um triângulo no plano cartesiano. Esta fórmula é 
        mais útil quando temos as coordenadas dos três vértices do triângulo.
        A fórmula utilizada é uma forma simplificada da fórmula de Shoelace (ou Gauss) para calcular 
        a área de um polígono. 
        A fórmula para calcular a área de um triângulo com os vértices (x1, y1), (x2, y2) e (x3, y3) é:
        Área = | x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2) | / 2
        Esta fórmula funciona em termos das coordenadas dos três vértices e é 
        derivada do cálculo do determinante de uma matriz 2D que contém as coordenadas dos pontos. 
*/

/*
2 - Explicação do return:
    return (areaABC == areaABP + areaBCP + areaCAP && areaABP > 0 && areaBCP > 0 && areaCAP > 0);
    - Contexto:
    areaABC: Área do triângulo formado pelos três vértices originais A, B e C (o triângulo original).
    areaABP: Área do triângulo formado pelos vértices A, B e o ponto a ser testado P.
    areaBCP: Área do triângulo formado pelos vértices B, C e P.
    areaCAP: Área do triângulo formado pelos vértices C, A e P.


    Agora, vamos detalhar o que acontece em cada parte do return:
        1. areaABC == areaABP + areaBCP + areaCAP
        Esta expressão verifica se a soma das áreas dos três pequenos triângulos ( ABP, BCP e CAP) 
        é igual à área do triângulo original (ABC).

            . Se o ponto P estiver dentro do triângulo, a soma das áreas dos três triângulos menores
            será igual à área do triângulo original.
            . Se o ponto P estiver fora do triângulo, a soma das áreas será maior ou menor do que a área do triângulo original
            (dependendo de onde P está no plano).

        Assim, o programa usa essa comparação para garantir que o ponto 
        P está dentro dos limites do triângulo.

        2. areaABP > 0 && areaBCP > 0 && areaCAP > 0
        Aqui, o código verifica se todas as áreas dos triângulos menores são maiores que 0.

        . Se qualquer uma das áreas for 0, significa que o ponto P está sobre uma das linhas 
        do triângulo (ou seja, sobre um dos lados do triângulo, não dentro dele).
        . Se todas as áreas forem maiores que 0, significa que o ponto P não está em 
        nenhuma linha do triângulo e que está dentro do triângulo.

        Resumo da lógica:
        O return apenas retornará true (ou seja, que o ponto P está dentro do triângulo) 
        se ambos os critérios forem satisfeitos:
        - A soma das áreas dos três triângulos menores é igual à área do triângulo original.
        - As áreas dos três triângulos menores são maiores que 0 (ou seja, P não está sobre uma linha).
        Exemplo visual:
            . Se o triângulo original for ABC e o ponto P estiver dentro do triângulo, a soma 
            das áreas dos triângulos ABP, BCP e CAP será igual à área de ABC, e todas as áreas serão positivas.
            . Se P estiver fora do triângulo, a soma das áreas será diferente da área do triângulo original, 
            ou uma das áreas será 0 (se P estiver sobre uma das bordas do triângulo).
        
        Em resumo:
        O return verifica duas coisas simultaneamente:

        - Se a soma das áreas menores é igual à área original (para garantir que 
        P está dentro do triângulo).
        - Se P não está sobre uma borda (todas as áreas são maiores que 0).
*/

#include "Point.hpp"
#include "Fixed.hpp"

// Função auxiliar para calcular a área de um triângulo usando uma fórmula simplificada da fórmula de "Shoelace" ou Gauss para calcular a área dum polígono
static float area(const Point p1, const Point p2, const Point p3) 
{
    // Fórmula determinante 2D para calcular a área
    return abs((p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat()) +
                p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat()) +
                p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat())) / 2);
}
                    
// Função que verifica se um ponto está dentro do triângulo
bool bsp(Point const a, Point const b, Point const c, Point const point) 
{
    // Calcula a área do triângulo principal (ABC)
    float areaABC = area(a, b, c);

    // Calcula as áreas dos subtriângulos formados com o ponto
    float areaABP = area(a, b, point);
    float areaBCP = area(b, c, point);
    float areaCAP = area(c, a, point);

    // Verifica se a soma das áreas dos subtriângulos é igual à área do triângulo principal
    // Também garante que o ponto não está nas arestas
    return (areaABC == areaABP + areaBCP + areaCAP && areaABP > 0 && areaBCP > 0 && areaCAP > 0);
}
