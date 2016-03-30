using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/***
通过GetInvocationList（）获得委托连中每一个委托
?****/
namespace Lightcai
{


    internal sealed class Light
    {
        public String SwitchPosition()
        {
            return "The Light is off";
        }
    }

    internal sealed class Fan
    {
        public String Speed()
        {
            throw new InvalidOperationException("The fan broken due to overheading");
        }
    }

    internal sealed class Speaker{
        public String Volume()
        {
            return "The Volume is off";
        }
}
    public sealed class Program
    {
        private delegate String GetStatus();
        static void Main(string[] args)
        {
            GetStatus getStatus = null;

            getStatus += new GetStatus(new Light().SwitchPosition);
            getStatus += new GetStatus(new Fan().Speed);
            getStatus += new GetStatus(new Speaker().Volume);

            Console.WriteLine(GetComponentStatusReport(getStatus));
            Console.ReadLine();

        }

        private static String GetComponentStatusReport(GetStatus status)
        {

            if (status == null) return null;

            StringBuilder sb = new StringBuilder();

            //获得一个数组，其中每个元素都是一个链中的元素
            Delegate[] arrayOfDelegate = status.GetInvocationList();

            foreach(GetStatus getStatus in arrayOfDelegate)
            {
                try
                {
                    sb.AppendFormat("{0}{1}{1}", getStatus(), Environment.NewLine);

                }
                catch(InvalidOperationException e)
                {
                    Object componet = getStatus.Target;
                    sb.AppendFormat("Failed to get status from {1}{2}{0} Error:{3}{0}{0}",
                        Environment.NewLine,
                        (componet == null) ? " " : componet.GetType() + ".",
                    getStatus.Method.Name,e.Message);
                }
            }
            return sb.ToString();
        }
    }
}
