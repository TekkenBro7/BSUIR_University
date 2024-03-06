using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Calculator.Pages.CurrencyConverter.Entities;
using System.Text.Json;
using Microsoft.Extensions.DependencyInjection;

namespace Calculator.Pages.CurrencyConverter.Services
{
    class RateService : IRateService
    {
        private HttpClient _httpClient;
        private readonly List<string> CurAbbreviations = new() { "RUB", "EUR", "USD", "CHF", "CNY", "GBP" };
        public RateService(HttpClient httpClient) 
        {
            _httpClient = httpClient;
        }
        public IEnumerable<Rate>? GetRates(DateTime date)
        {
            List<Rate> rates = new();
            string uri = $"https://api.nbrb.by/exrates/rates?ondate={date:yyyy-MM-dd}&periodicity=0";
            var response = _httpClient.GetAsync(uri).Result;
            if (response.IsSuccessStatusCode)
            {
                string content = response.Content.ReadAsStringAsync().Result;
                rates = JsonSerializer.Deserialize<List<Rate>>(content);
            }
            return rates?.Where(x => CurAbbreviations.Contains(x.Cur_Abbreviation));
        }
    }
}
