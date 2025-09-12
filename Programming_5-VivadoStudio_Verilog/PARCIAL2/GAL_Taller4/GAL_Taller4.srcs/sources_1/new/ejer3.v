// Módulo Full Subtractor
module full_subtractor (
    input X,      // Primer bit de los números a restar
    input Y,      // Segundo bit de los números a restar
    input Bin,    // Acarreo de entrada
    output D,     // Diferencia
    output Bout   // Acarreo de salida
);

    assign D = (X ^ Y) ^ Bin;                  // Diferencia: X XOR Y XOR Bin
    assign Bout = (~X & (Y | Bin)) | ((X ^ Y) & Bin);  // Acarreo de salida

endmodule


// Módulo Parallel Subtractor
module parallel_subtractor (
    input [3:0] X,     // Bits de entrada X (X3, X2, X1, X0)
    input [3:0] Y,     // Bits de entrada Y (Y3, Y2, Y1, Y0)
    output [3:0] D,    // Diferencias de salida (D3, D2, D1, D0)
    output [3:0] Bout   // Acarreos de salida (B3, B2, B1, B0)
);

    wire B0_int, B1_int, B2_int;  // Señales intermedias para los acarreo

    // Instancias de los Full Subtractors
    full_subtractor U1 (
        .X(X[0]), .Y(Y[0]), .Bin(1'b0), 
        .D(D[0]), .Bout(B0_int)
    );

    full_subtractor U2 (
        .X(X[1]), .Y(Y[1]), .Bin(B0_int), 
        .D(D[1]), .Bout(B1_int)
    );

    full_subtractor U3 (
        .X(X[2]), .Y(Y[2]), .Bin(B1_int), 
        .D(D[2]), .Bout(B2_int)
    );

    full_subtractor U4 (
        .X(X[3]), .Y(Y[3]), .Bin(B2_int), 
        .D(D[3]), .Bout(Bout[3])
    );

    // Conectar el último acarreo de salida a la salida Bout
    assign Bout[0] = B0_int;
    assign Bout[1] = B1_int;
    assign Bout[2] = B2_int;

endmodule


// Testbench para Parallel Subtractor
module test_parallel_subtractor;
    reg [3:0] X;    // Valores de entrada X
    reg [3:0] Y;    // Valores de entrada Y
    wire [3:0] D;   // Diferencias de salida
    wire [3:0] Bout; // Acarreos de salida

    // Instanciamos el Parallel Subtractor
    parallel_subtractor uut (
        .X(X),
        .Y(Y),
        .D(D),
        .Bout(Bout)
    );

    initial begin
        // Inicializamos las entradas
        X = 4'b1010;   // Ejemplo: X = 10
        Y = 4'b0111;   // Ejemplo: Y = 7

        // Verificamos la salida en el simulador
        #10; // Esperamos 10 unidades de tiempo
        $display("X = %b, Y = %b, D = %b, Bout = %b", X, Y, D, Bout);

        // Cambiamos las entradas para probar diferentes casos
        X = 4'b1111;   // X = 15
        Y = 4'b0001;   // Y = 1
        #10;
        $display("X = %b, Y = %b, D = %b, Bout = %b", X, Y, D, Bout);

        X = 4'b1001;   // X = 9
        Y = 4'b0100;   // Y = 4
        #10;
        $display("X = %b, Y = %b, D = %b, Bout = %b", X, Y, D, Bout);
    end
endmodule
