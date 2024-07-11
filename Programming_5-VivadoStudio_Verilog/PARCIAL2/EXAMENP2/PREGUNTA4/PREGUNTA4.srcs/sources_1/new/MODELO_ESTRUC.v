    `timescale 1ns / 1ps
    
    module mux21(
        input A,
        input B,
        input S,
        output out
        );
        reg temp;
        
        always@(*) begin
            case (S)
                1'b0: temp = A;
                1'b1: temp = B;
            endcase
        end
        assign out = temp;
    endmodule
    
    module MODELO_ESTRUC(
            input A,
            input B,
            input S1,
            input C,
            input D,
            input S2,
            output F
            );
            
            wire t1, t2;
            
            // Mapeo Implicito //
            mux21 mux1(A, B, S1, t1);
     
            // Mapeo Implicito //
            mux21 mux2(C, D, S1, t2);
            
            // Mapeo Implicito //
            mux21 mux3(t1, t2, S2, F);
           
    endmodule
