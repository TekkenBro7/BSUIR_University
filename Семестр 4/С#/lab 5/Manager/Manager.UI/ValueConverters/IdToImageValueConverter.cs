using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Manager.UI.ValueConverters
{
    internal class IdToImageValueConverter : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            string fileName = "image" + value.ToString() + ".jpg";          
            string filePath = Path.Combine(FileSystem.Current.AppDataDirectory, fileName); // "C:\\Manager\\Manager.UI\\Resources\\Images"
            if (!File.Exists(filePath)) 
            {
                return "empty_photo.jpg";
            }
            return filePath;
        }
        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {
            throw new NotImplementedException();
        }
    }
}
