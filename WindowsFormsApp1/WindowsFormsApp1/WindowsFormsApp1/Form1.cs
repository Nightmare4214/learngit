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
        private int priority(char c)
        {
            switch (c)
            {
                case '*':
                case '/':
                    return 3;
                case '+':
                case '-':
                    return 2;
                case '#':
                    return 1;
                default:
                    return 0;
            }

        }
        private bool compare(char a,char b)
        {
            return priority(a) > priority(b);
        }
        private double calculate(double a,double b,char c)
        {
            switch (c)
            {
                case '+':
                    return a + b;
                case '-':
                    return a - b;
                case '*':
                    return a * b;
                case '/':
                    if (b == 0) throw new Exception("divid by zero");
                    return a / b;
                default:
                    throw new Exception("wrong express");
            }
        }
        //中缀表达式求值
        private string getResult(string express)
        {
            char lastChar = express[express.Length - 1];
            if (!char.IsNumber(lastChar)&&lastChar!='.')
            {
                express=express.Substring(0, express.Length - 1);
            }
            try {
                Stack<char> operation = new Stack<char>();
                operation.Push('#');
                Stack<double> num = new Stack<double>();
                for (int i = 0; i < express.Length; ++i)
                {
                    string temp = "";
                    while (i<express.Length&&(char.IsNumber(express[i]) || express[i] == '.'))
                    {
                        temp += express[i];
                        ++i;
                    }
                    num.Push(Convert.ToDouble(temp));
                    if (i == express.Length) break;
                    char op = express[i];
                    while (!compare(op, operation.Peek()))
                    {
                        double b = num.Peek();
                        num.Pop();
                        double a = num.Peek();
                        num.Pop();
                        num.Push(calculate(a, b, operation.Pop()));
                    }
                    operation.Push(op);
                }
                while (operation.Peek() != '#')
                {
                    double b = num.Peek();
                    num.Pop();
                    double a = num.Peek();
                    num.Pop();
                    num.Push(calculate(a, b, operation.Pop()));
                }
                return Convert.ToString(num.Peek());
            }
            catch(Exception e)
            {
                return e.Message;
            }
        }
        private void doClear()
        {
            if(clear)result.Text = "0";
            clear = false;
        }
        private int getPos()
        {
            string text = result.Text;
            int pos = text.Length - 1;
            for(int i = text.Length - 1; i >= 0; --i)
            {
                if (char.IsNumber(text[i])||text[i]=='.')
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
        //返回最后一个操作数，如果最后是操作符，则返回空
        private string getLastOperator()
        {
            string text = result.Text;
            string temp = text.Substring(getPos());
            if (!char.IsNumber(temp[0]) && temp[0] != '.') return "";
            else return temp;
        }
        private void Num_Click(object sender, EventArgs e)
        {
            doClear();
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
        private void Point_Click(object sender, EventArgs e)
        {
            doClear();
            string text = result.Text;
            string op = getLastOperator();
            if (op == "") result.Text += "0.";
            else if (op.IndexOf('.') != -1) return;
            else result.Text = result.Text + '.';
        }
        private void Operation_Click(object sender,EventArgs e)
        {
            doClear();
            string text = result.Text;
            string operation = ((Button)sender).Text;
            char lastChar = text[text.Length - 1];
            if (char.IsNumber(lastChar))
            {
                result.Text += operation;
            }else
            {
                result.Text = result.Text.Substring(0, text.Length - 1) + operation;
            }
        }
        private void Equal_Click(object sender,EventArgs e)
        {
            string text = result.Text;
            result.Text = getResult(text);
            clear = true;
        }
    }
}
