namespace PREGUNTA_4_EXAMEN_FINAL_PRO2_YU
{
    partial class Form1
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.radProfesor = new System.Windows.Forms.RadioButton();
            this.radEstudiante = new System.Windows.Forms.RadioButton();
            this.grbTipoPersona = new System.Windows.Forms.GroupBox();
            this.btnCapturaDatos = new System.Windows.Forms.Button();
            this.btnMostrarDatos = new System.Windows.Forms.Button();
            this.grbDatos = new System.Windows.Forms.GroupBox();
            this.txtCalificacion = new System.Windows.Forms.TextBox();
            this.txtSueldo = new System.Windows.Forms.TextBox();
            this.txtNombre = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.grbTipoPersona.SuspendLayout();
            this.grbDatos.SuspendLayout();
            this.SuspendLayout();
            // 
            // radProfesor
            // 
            this.radProfesor.AutoSize = true;
            this.radProfesor.Location = new System.Drawing.Point(21, 40);
            this.radProfesor.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.radProfesor.Name = "radProfesor";
            this.radProfesor.Size = new System.Drawing.Size(94, 24);
            this.radProfesor.TabIndex = 0;
            this.radProfesor.TabStop = true;
            this.radProfesor.Text = "Profesor";
            this.radProfesor.UseVisualStyleBackColor = true;
            this.radProfesor.CheckedChanged += new System.EventHandler(this.radProfesor_CheckedChanged);
            // 
            // radEstudiante
            // 
            this.radEstudiante.AutoSize = true;
            this.radEstudiante.Location = new System.Drawing.Point(21, 72);
            this.radEstudiante.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.radEstudiante.Name = "radEstudiante";
            this.radEstudiante.Size = new System.Drawing.Size(111, 24);
            this.radEstudiante.TabIndex = 1;
            this.radEstudiante.TabStop = true;
            this.radEstudiante.Text = "Estudiante";
            this.radEstudiante.UseVisualStyleBackColor = true;
            this.radEstudiante.CheckedChanged += new System.EventHandler(this.radEstudiante_CheckedChanged);
            // 
            // grbTipoPersona
            // 
            this.grbTipoPersona.Controls.Add(this.radProfesor);
            this.grbTipoPersona.Controls.Add(this.radEstudiante);
            this.grbTipoPersona.Location = new System.Drawing.Point(36, 49);
            this.grbTipoPersona.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.grbTipoPersona.Name = "grbTipoPersona";
            this.grbTipoPersona.Padding = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.grbTipoPersona.Size = new System.Drawing.Size(172, 125);
            this.grbTipoPersona.TabIndex = 2;
            this.grbTipoPersona.TabStop = false;
            this.grbTipoPersona.Text = "Tipo de personas";
            // 
            // btnCapturaDatos
            // 
            this.btnCapturaDatos.Location = new System.Drawing.Point(321, 49);
            this.btnCapturaDatos.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btnCapturaDatos.Name = "btnCapturaDatos";
            this.btnCapturaDatos.Size = new System.Drawing.Size(84, 65);
            this.btnCapturaDatos.TabIndex = 3;
            this.btnCapturaDatos.Text = "Capturar datos";
            this.btnCapturaDatos.UseVisualStyleBackColor = true;
            this.btnCapturaDatos.Click += new System.EventHandler(this.btnCapturaDatos_Click);
            // 
            // btnMostrarDatos
            // 
            this.btnMostrarDatos.Location = new System.Drawing.Point(321, 145);
            this.btnMostrarDatos.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btnMostrarDatos.Name = "btnMostrarDatos";
            this.btnMostrarDatos.Size = new System.Drawing.Size(84, 62);
            this.btnMostrarDatos.TabIndex = 4;
            this.btnMostrarDatos.Text = "Mostrar Datos";
            this.btnMostrarDatos.UseVisualStyleBackColor = true;
            this.btnMostrarDatos.Click += new System.EventHandler(this.btnMostrarDatos_Click);
            // 
            // grbDatos
            // 
            this.grbDatos.Controls.Add(this.txtCalificacion);
            this.grbDatos.Controls.Add(this.txtSueldo);
            this.grbDatos.Controls.Add(this.txtNombre);
            this.grbDatos.Controls.Add(this.label3);
            this.grbDatos.Controls.Add(this.label2);
            this.grbDatos.Controls.Add(this.label1);
            this.grbDatos.Location = new System.Drawing.Point(36, 254);
            this.grbDatos.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.grbDatos.Name = "grbDatos";
            this.grbDatos.Padding = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.grbDatos.Size = new System.Drawing.Size(400, 180);
            this.grbDatos.TabIndex = 2;
            this.grbDatos.TabStop = false;
            this.grbDatos.Text = "Datos de la persona";
            this.grbDatos.Enter += new System.EventHandler(this.grbDatos_Enter);
            // 
            // txtCalificacion
            // 
            this.txtCalificacion.Location = new System.Drawing.Point(150, 132);
            this.txtCalificacion.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.txtCalificacion.Name = "txtCalificacion";
            this.txtCalificacion.Size = new System.Drawing.Size(69, 26);
            this.txtCalificacion.TabIndex = 5;
            this.txtCalificacion.TextChanged += new System.EventHandler(this.txtCalificacion_TextChanged);
            // 
            // txtSueldo
            // 
            this.txtSueldo.Location = new System.Drawing.Point(150, 92);
            this.txtSueldo.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.txtSueldo.Name = "txtSueldo";
            this.txtSueldo.Size = new System.Drawing.Size(112, 26);
            this.txtSueldo.TabIndex = 4;
            this.txtSueldo.TextChanged += new System.EventHandler(this.txtSueldo_TextChanged);
            // 
            // txtNombre
            // 
            this.txtNombre.Location = new System.Drawing.Point(150, 56);
            this.txtNombre.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.txtNombre.Name = "txtNombre";
            this.txtNombre.Size = new System.Drawing.Size(204, 26);
            this.txtNombre.TabIndex = 3;
            this.txtNombre.TextChanged += new System.EventHandler(this.txtNombre_TextChanged);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(39, 132);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(89, 20);
            this.label3.TabIndex = 2;
            this.label3.Text = "Calificación";
            this.label3.Click += new System.EventHandler(this.label3_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(62, 92);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(59, 20);
            this.label2.TabIndex = 1;
            this.label2.Text = "Sueldo";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(62, 56);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(65, 20);
            this.label1.TabIndex = 0;
            this.label1.Text = "Nombre";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(483, 468);
            this.Controls.Add(this.grbDatos);
            this.Controls.Add(this.btnMostrarDatos);
            this.Controls.Add(this.btnCapturaDatos);
            this.Controls.Add(this.grbTipoPersona);
            this.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.Name = "Form1";
            this.Text = "PERSONAS DE UNA ESCUELA";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.grbTipoPersona.ResumeLayout(false);
            this.grbTipoPersona.PerformLayout();
            this.grbDatos.ResumeLayout(false);
            this.grbDatos.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.RadioButton radProfesor;
        private System.Windows.Forms.RadioButton radEstudiante;
        private System.Windows.Forms.GroupBox grbTipoPersona;
        private System.Windows.Forms.Button btnCapturaDatos;
        private System.Windows.Forms.Button btnMostrarDatos;
        private System.Windows.Forms.GroupBox grbDatos;
        private System.Windows.Forms.TextBox txtCalificacion;
        private System.Windows.Forms.TextBox txtSueldo;
        private System.Windows.Forms.TextBox txtNombre;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
    }
}

