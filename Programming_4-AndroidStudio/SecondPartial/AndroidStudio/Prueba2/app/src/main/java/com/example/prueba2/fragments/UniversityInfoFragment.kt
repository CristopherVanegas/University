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
private const val ARG_FACULTAD = "facultad_arg"
private const val ARG_CARRERA = "carrera_arg"

/**
 * A simple [Fragment] subclass.
 * Use the [UniversityInfoFragment.newInstance] factory method to
 * create an instance of this fragment.
 */
class UniversityInfoFragment : Fragment() {
    // TODO: Rename and change types of parameters
    private var param1: String? = null
    private var param2: String? = null
    private var facultad: String? = null
    private var carrera: String? = null
    lateinit var txtViewFacultadIntent: TextView
    lateinit var txtViewCarreraIntent: TextView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
    }

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        var view = inflater.inflate(R.layout.fragment_university_info, container, false)
        txtViewFacultadIntent = view.findViewById(R.id.txtViewFacultadIntent)
        txtViewCarreraIntent = view.findViewById(R.id.txtViewCarreraIntent)

        arguments?.let {
            param1 = it.getString(ARG_PARAM1)
            param2 = it.getString(ARG_PARAM2)

            facultad = it.getString(ARG_FACULTAD)
            carrera = it.getString(ARG_CARRERA)
            txtViewFacultadIntent.text = facultad
            txtViewCarreraIntent.text = carrera
        }
        // Inflate the layout for this fragment
        return view
    }

    companion object {
        /**
         * Use this factory method to create a new instance of
         * this fragment using the provided parameters.
         *
         * @param param1 Parameter 1.
         * @param param2 Parameter 2.
         * @return A new instance of fragment UniversityInfoFragment.
         */
        // TODO: Rename and change types and number of parameters
        @JvmStatic
        fun newInstance(param1: String, param2: String) =
            UniversityInfoFragment().apply {
                arguments = Bundle().apply {
                    putString(ARG_PARAM1, param1)
                    putString(ARG_PARAM2, param2)
                }
            }
    }
}