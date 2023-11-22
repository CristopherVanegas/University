package com.example.prueba2

import android.content.Intent
import android.os.Bundle
import android.widget.Button
import androidx.appcompat.app.AppCompatActivity
import com.example.prueba2.fragments.BlankFragment
import com.example.prueba2.fragments.PersonalInfoFragment
import com.example.prueba2.fragments.UniversityInfoFragment

class InfoEstudianteActivity : AppCompatActivity() {

    private lateinit var personalInfoFragment: PersonalInfoFragment
    private lateinit var universityInfoFragment: UniversityInfoFragment
    private lateinit var blankFragment: BlankFragment

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.info_estudiante)

        // Inicializar los fragmentos
        personalInfoFragment = PersonalInfoFragment()
        universityInfoFragment = UniversityInfoFragment()
        blankFragment = BlankFragment()

        // Mostrar el fragmento de información personal por defecto
        supportFragmentManager.beginTransaction().apply {
            replace(R.id.frame, blankFragment)
            commit()
        }

        // Manejar el clic en el botón de información personal
        findViewById<Button>(R.id.InfoPersonal).setOnClickListener {
            // Obtener los datos enviados desde la actividad principal
            val cedula = intent.getStringExtra("CEDULA_INTENT")
            val nombre = intent.getStringExtra("NOMBRE_INTENT")
            val correo = intent.getStringExtra("CORREO_INTENT")
            val direccion = intent.getStringExtra("DIRECCION_INTENT")
            val inicial_nombre = intent.getStringExtra("INCIAL_NOMBRE_INTENT")

            // Crea un fragment como borrador para luego actualizar sus arguments
            var fragmento = PersonalInfoFragment()

            // Crea un bundle con los datos receptados del Intent
            var bundle : Bundle = Bundle();
            bundle.putString("cedula_arg", cedula)
            bundle.putString("nombre_arg", nombre)
            bundle.putString("correo_arg", correo)
            bundle.putString("direccion_arg", direccion)
            bundle.putString("inicial_nombre_arg", inicial_nombre)

            // Envia el bundle a los argumentos del Fragment
            fragmento.arguments = bundle

            // Realiza la transaccion entre en fragment con parametros y sin parametros
            var fragTrans = supportFragmentManager.beginTransaction()
            fragTrans.replace(R.id.frame, fragmento)
            fragTrans.commit()
        }

        // Manejar el clic en el botón de información de la universidad
        findViewById<Button>(R.id.InfoUniversidad).setOnClickListener {
            // Obtener los datos enviados desde la actividad principal
            val facultad = intent.getStringExtra("FACULTAD_INTENT")
            val carrera = intent.getStringExtra("CARRERA_INTENT")

            // Crea un fragment como borrador para luego actualizar sus arguments
            var fragmento = UniversityInfoFragment()

            // Crea un bundle con los datos receptados del Intent
            var bundle:Bundle = Bundle();
            bundle.putString("facultad_arg", facultad)
            bundle.putString("carrera_arg", carrera)

            // Envia el bundle a los argumentos del Fragment
            fragmento.arguments = bundle

            // Realiza la transaccion entre en fragment con parametros y sin parametros
            var fragTrans = supportFragmentManager.beginTransaction()
            fragTrans.replace(R.id.frame, fragmento)
            fragTrans.commit()
        }

        // Boton para regresar a la actividad Main
        val btnGoBack = findViewById<Button>(R.id.btnGoBack)
        btnGoBack.setOnClickListener() {
            val intent = Intent(this, MainActivity::class.java)
            startActivity(intent)
        }

    }
}
