#define DEBUG
using System;
namespace helloworld
{
    [AttributeUsage(AttributeTargets.Property)]
    class ValidAttribute : Attribute
    {
        public ValidAttribute(int maxLength)
        {
            _maxLength = maxLength;
        }
        private int _maxLength;
        public int MaxLength   //这里的get和set和vue里getter setter很像，不得不说前端在吸收各种语言框架的优点
        {
            get
            {
                return _maxLength;
            }
            set
            {
                _maxLength = value;
            }
        }
    }
    class Account
    {
        [Valid(5)]
        public String Name { get; set; }
        [Valid(10)]
        public String Pwd { get; set; }
    }
    class ValidFunc
    {
        public void Validate(object obj)
        {
            var t = obj.GetType();
            var properties = t.GetProperties();
            foreach (var property in properties)
            {
                if (!property.IsDefined(typeof(ValidAttribute), false)) continue;
                var attributes = property.GetCustomAttributes(false);
                foreach (var attribute in attributes)
                {
                    var maxLength = (int)attribute.GetType().GetProperty("MaxLength").GetValue(attribute);

                    var propertyValue = property.GetValue(obj) as string;
                    if (propertyValue == null)
                        throw new Exception("value is null.");
                    if (propertyValue.Length > maxLength)
                        throw new Exception(string.Format("属性{0}的值{1}超过了限制长度{2}", property.Name, propertyValue, maxLength));
                }
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            var Account = new Account() { Name = "Parz1", Pwd = "123" };
            try
            {
                ValidFunc vf = new ValidFunc();
                vf.Validate(Account);
                Console.WriteLine(vf);
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            Console.ReadLine();
        }
    }
}
