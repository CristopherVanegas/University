`timescale 1ns / 1ps

// fa = full added
// los primitivos nos permiten modelar compuertas logicas

/* ASIGNACION DE PUERTOS */
// Explicito = mapeando por nombre
// Implicito = mapeando por posicion

module fa_primitivos(
    input A,
    input B,
    input Cin,
    output Cout,
    output S
    );
    
    wire t1, t2, t3;
    // ^ es el operador para xor
    // xor(salida, entrada 1, entrada 2)
    xor(t1, A, B);
    xor(S, t1, Cin);
    // and(salida, entrada 1, entrada 2)
    and(t2, t1,  Cin);
    and(t3, A, B);
    or(Cout, t2, t3);
endmodule









