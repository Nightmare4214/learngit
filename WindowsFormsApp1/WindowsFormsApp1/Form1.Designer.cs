﻿namespace WindowsFormsApp1
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.result = new System.Windows.Forms.Label();
            this.Seven = new System.Windows.Forms.Button();
            this.Eight = new System.Windows.Forms.Button();
            this.Nine = new System.Windows.Forms.Button();
            this.Four = new System.Windows.Forms.Button();
            this.Five = new System.Windows.Forms.Button();
            this.Six = new System.Windows.Forms.Button();
            this.One = new System.Windows.Forms.Button();
            this.Two = new System.Windows.Forms.Button();
            this.Three = new System.Windows.Forms.Button();
            this.Zero = new System.Windows.Forms.Button();
            this.button11 = new System.Windows.Forms.Button();
            this.Divid = new System.Windows.Forms.Button();
            this.Multiply = new System.Windows.Forms.Button();
            this.Minus = new System.Windows.Forms.Button();
            this.Plus = new System.Windows.Forms.Button();
            this.Equal = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // result
            // 
            this.result.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.result.Font = new System.Drawing.Font("宋体", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.result.Location = new System.Drawing.Point(22, 17);
            this.result.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.result.Name = "result";
            this.result.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.result.Size = new System.Drawing.Size(448, 94);
            this.result.TabIndex = 0;
            this.result.Text = "0";
            // 
            // Seven
            // 
            this.Seven.Location = new System.Drawing.Point(24, 123);
            this.Seven.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Seven.Name = "Seven";
            this.Seven.Size = new System.Drawing.Size(60, 64);
            this.Seven.TabIndex = 1;
            this.Seven.Text = "7";
            this.Seven.UseVisualStyleBackColor = true;
            this.Seven.Click += new System.EventHandler(this.Num_Click);
            // 
            // Eight
            // 
            this.Eight.Location = new System.Drawing.Point(124, 123);
            this.Eight.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Eight.Name = "Eight";
            this.Eight.Size = new System.Drawing.Size(60, 64);
            this.Eight.TabIndex = 2;
            this.Eight.Text = "8";
            this.Eight.UseVisualStyleBackColor = true;
            this.Eight.Click += new System.EventHandler(this.Num_Click);
            // 
            // Nine
            // 
            this.Nine.Location = new System.Drawing.Point(225, 123);
            this.Nine.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Nine.Name = "Nine";
            this.Nine.Size = new System.Drawing.Size(60, 64);
            this.Nine.TabIndex = 3;
            this.Nine.Text = "9";
            this.Nine.UseVisualStyleBackColor = true;
            this.Nine.Click += new System.EventHandler(this.Num_Click);
            // 
            // Four
            // 
            this.Four.Location = new System.Drawing.Point(24, 220);
            this.Four.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Four.Name = "Four";
            this.Four.Size = new System.Drawing.Size(60, 64);
            this.Four.TabIndex = 4;
            this.Four.Text = "4";
            this.Four.UseVisualStyleBackColor = true;
            this.Four.Click += new System.EventHandler(this.Num_Click);
            // 
            // Five
            // 
            this.Five.Location = new System.Drawing.Point(124, 220);
            this.Five.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Five.Name = "Five";
            this.Five.Size = new System.Drawing.Size(60, 64);
            this.Five.TabIndex = 5;
            this.Five.Text = "5";
            this.Five.UseVisualStyleBackColor = true;
            this.Five.Click += new System.EventHandler(this.Num_Click);
            // 
            // Six
            // 
            this.Six.Location = new System.Drawing.Point(225, 220);
            this.Six.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Six.Name = "Six";
            this.Six.Size = new System.Drawing.Size(60, 64);
            this.Six.TabIndex = 6;
            this.Six.Text = "6";
            this.Six.UseVisualStyleBackColor = true;
            this.Six.Click += new System.EventHandler(this.Num_Click);
            // 
            // One
            // 
            this.One.Location = new System.Drawing.Point(24, 314);
            this.One.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.One.Name = "One";
            this.One.Size = new System.Drawing.Size(60, 64);
            this.One.TabIndex = 7;
            this.One.Text = "1";
            this.One.UseVisualStyleBackColor = true;
            this.One.Click += new System.EventHandler(this.Num_Click);
            // 
            // Two
            // 
            this.Two.Location = new System.Drawing.Point(124, 314);
            this.Two.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Two.Name = "Two";
            this.Two.Size = new System.Drawing.Size(60, 64);
            this.Two.TabIndex = 8;
            this.Two.Text = "2";
            this.Two.UseVisualStyleBackColor = true;
            this.Two.Click += new System.EventHandler(this.Num_Click);
            // 
            // Three
            // 
            this.Three.Location = new System.Drawing.Point(225, 314);
            this.Three.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Three.Name = "Three";
            this.Three.Size = new System.Drawing.Size(60, 64);
            this.Three.TabIndex = 9;
            this.Three.Text = "3";
            this.Three.UseVisualStyleBackColor = true;
            this.Three.Click += new System.EventHandler(this.Num_Click);
            // 
            // Zero
            // 
            this.Zero.Location = new System.Drawing.Point(24, 403);
            this.Zero.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Zero.Name = "Zero";
            this.Zero.Size = new System.Drawing.Size(160, 64);
            this.Zero.TabIndex = 10;
            this.Zero.Text = "0";
            this.Zero.UseVisualStyleBackColor = true;
            this.Zero.Click += new System.EventHandler(this.Num_Click);
            // 
            // button11
            // 
            this.button11.Location = new System.Drawing.Point(225, 403);
            this.button11.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.button11.Name = "button11";
            this.button11.Size = new System.Drawing.Size(60, 64);
            this.button11.TabIndex = 11;
            this.button11.Text = ".";
            this.button11.UseVisualStyleBackColor = true;
            this.button11.Click += new System.EventHandler(this.Point_Click);
            // 
            // Divid
            // 
            this.Divid.Location = new System.Drawing.Point(316, 123);
            this.Divid.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Divid.Name = "Divid";
            this.Divid.Size = new System.Drawing.Size(60, 64);
            this.Divid.TabIndex = 12;
            this.Divid.Text = "/";
            this.Divid.UseVisualStyleBackColor = true;
            this.Divid.Click += new System.EventHandler(this.Operation_Click);
            // 
            // Multiply
            // 
            this.Multiply.Location = new System.Drawing.Point(316, 220);
            this.Multiply.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Multiply.Name = "Multiply";
            this.Multiply.Size = new System.Drawing.Size(60, 64);
            this.Multiply.TabIndex = 13;
            this.Multiply.Text = "*";
            this.Multiply.UseVisualStyleBackColor = true;
            this.Multiply.Click += new System.EventHandler(this.Operation_Click);
            // 
            // Minus
            // 
            this.Minus.Location = new System.Drawing.Point(316, 314);
            this.Minus.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Minus.Name = "Minus";
            this.Minus.Size = new System.Drawing.Size(60, 64);
            this.Minus.TabIndex = 14;
            this.Minus.Text = "-";
            this.Minus.UseVisualStyleBackColor = true;
            this.Minus.Click += new System.EventHandler(this.Operation_Click);
            // 
            // Plus
            // 
            this.Plus.Location = new System.Drawing.Point(316, 403);
            this.Plus.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Plus.Name = "Plus";
            this.Plus.Size = new System.Drawing.Size(60, 64);
            this.Plus.TabIndex = 15;
            this.Plus.Text = "+";
            this.Plus.UseVisualStyleBackColor = true;
            this.Plus.Click += new System.EventHandler(this.Operation_Click);
            // 
            // Equal
            // 
            this.Equal.Location = new System.Drawing.Point(408, 123);
            this.Equal.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Equal.Name = "Equal";
            this.Equal.Size = new System.Drawing.Size(62, 344);
            this.Equal.TabIndex = 16;
            this.Equal.Text = "=";
            this.Equal.UseVisualStyleBackColor = true;
            this.Equal.Click += new System.EventHandler(this.Equal_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(512, 503);
            this.Controls.Add(this.Equal);
            this.Controls.Add(this.Plus);
            this.Controls.Add(this.Minus);
            this.Controls.Add(this.Multiply);
            this.Controls.Add(this.Divid);
            this.Controls.Add(this.button11);
            this.Controls.Add(this.Zero);
            this.Controls.Add(this.Three);
            this.Controls.Add(this.Two);
            this.Controls.Add(this.One);
            this.Controls.Add(this.Six);
            this.Controls.Add(this.Five);
            this.Controls.Add(this.Four);
            this.Controls.Add(this.Nine);
            this.Controls.Add(this.Eight);
            this.Controls.Add(this.Seven);
            this.Controls.Add(this.result);
            this.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Label result;
        private System.Windows.Forms.Button Seven;
        private System.Windows.Forms.Button Eight;
        private System.Windows.Forms.Button Nine;
        private System.Windows.Forms.Button Four;
        private System.Windows.Forms.Button Five;
        private System.Windows.Forms.Button Six;
        private System.Windows.Forms.Button One;
        private System.Windows.Forms.Button Two;
        private System.Windows.Forms.Button Three;
        private System.Windows.Forms.Button Zero;
        private System.Windows.Forms.Button button11;
        private System.Windows.Forms.Button Divid;
        private System.Windows.Forms.Button Multiply;
        private System.Windows.Forms.Button Minus;
        private System.Windows.Forms.Button Plus;
        private System.Windows.Forms.Button Equal;
    }
}

