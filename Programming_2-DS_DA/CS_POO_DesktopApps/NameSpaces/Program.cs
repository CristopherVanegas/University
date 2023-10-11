using BancoARG.Gestion;
using System;

namespace BancoARG {
    namespace Gestion
    {
        public class CtaCte { }
        public class CajaAhorro { }
    }
}

// Referencia "Full"
BancoARG.Gestion.CtaCte;
BancoARG.Gestion.CajaAhorro;


// Referencia "Corta"
using BancoARRG.Gestion;
CtaCte cc = new CtaCte();
CajaAhorro ca = new CajaAhorro();

