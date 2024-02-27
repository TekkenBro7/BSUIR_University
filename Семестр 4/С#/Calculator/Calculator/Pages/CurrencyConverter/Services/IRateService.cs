using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Calculator.Pages.CurrencyConverter.Entities;
using Microsoft.Extensions.DependencyInjection;

namespace Calculator.Pages.CurrencyConverter.Services
{
    public interface IRateService
    {
        IEnumerable<Rate> GetRates(DateTime date);
    }
}
