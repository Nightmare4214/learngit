using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        bool clear;
        public Form1()
        {
            InitializeComponent();
            clear = false;
        }
        private void doClear()
        {
            result.Text = "0";
            clear = false;
        }
        private int getPos()
        {
            string text = result.Text;
            int pos = text.Length - 1;
            for(int i = text.Length - 1; i >= 0; --i)
            {
                if (char.IsNumber(text[i]))
                {
                    pos = i;
                }
                else
                {
                    return pos;
                }
            }
            return 0;
        }
        private int findFirstNotOf(string text,char target)
        {
            for(int i = 0; i < text.Length; ++i)
            {
                if (text[i] != target)
                {
                    return i;
                }
            }
            return -1;

        }
        private void Num_Click(object sender, EventArgs e)
        {
            if (clear)
            {
                doClear();
            }
            string num = ((Button)sender).Text;
            string text = result.Text;
            string op = text.Substring(getPos());
            //操作符或者小数点结尾
            if(!char.IsNumber(text[text.Length-1])&& text[text.Length - 1] != '.')
            {
                result.Text += num;
            }
            else
            {
                //前缀0不加0
                if (findFirstNotOf(op, '0') == -1 && num == "0") return;
                
                if (op == "0") result.Text = text.Substring(0, text.Length - 1) + num;
                else result.Text += num;
            }
            
        }
    }
}
