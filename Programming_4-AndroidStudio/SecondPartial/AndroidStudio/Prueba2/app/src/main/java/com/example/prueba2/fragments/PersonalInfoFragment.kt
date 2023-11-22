package com.example.prueba2.fragments

import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.TextView
import com.example.prueba2.R

// TODO: Rename parameter arguments, choose names that match
// the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
private const val ARG_PARAM1 = "param1"
private const val ARG_PARAM2 = "param2"
private const val ARG_CEDULA = "cedula_arg"
private const val ARG_NOMBRE = "nombre_arg"
private const val ARG_CORREO = "correo_arg"
private const val ARG_DIRECCION = "direccion_arg"
private const val ARG_INIC_NOMBRE = "inicial_nombre_arg"

/**
 * A simple [Fragment] subclass.
 * Use the [PersonalInfoFragment.newInstance] factory method to
 * create an instance of this fragment.
 */
class PersonalInfoFragment : Fragment() {
    // TODO: Rename and change types of parameters
    private var param1: String? = null
    private var param2: String? = null
    private var cedula: String? = null
    private var nombre: String? = null
    private var correo: String? = null
    private var direccion: String? = null
    lateinit var txtViewCedulaArg: TextView
    lateinit var txtViewNombreArg: TextView
    lateinit var txtViewCorreoArg: TextView
    lateinit var txtViewDireccionArg: TextView


    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
    }

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        var view = inflater.inflate(R.layout.fragment_personal_info, container, false)
        txtViewCedulaArg = view.findViewById(R.id.txtViewCedulaArg)
        txtViewNombreArg = view.findViewById(R.id.txtViewNombreArg)
        txtViewCorreoArg = view.findViewById(R.id.txtViewCorreoArg)
        txtViewDireccionArg = view.findViewById(R.id.txtViewDireccionArg)

        arguments?.let {
            nombre = it.getString(ARG_NOMBRE)
            cedula = it.getString(ARG_CEDULA)
            correo = it.getString(ARG_CORREO)
            direccion = it.getString(ARG_DIRECCION)

            txtViewCedulaArg.text = cedula
            txtViewNombreArg.text = nombre
            txtViewCorreoArg.text = correo
            txtViewDireccionArg.text = direccion
        }

        // Inflate the layout for this fragment
        return view
    }
}