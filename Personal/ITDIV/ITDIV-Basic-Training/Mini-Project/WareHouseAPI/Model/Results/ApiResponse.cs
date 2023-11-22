namespace WareHouseAPI.Model.Results
{
    public class ApiResponse<T>
    {
        public T Data { get; set; }
        public string RequestMethod { get; set; }
        public bool StatusCode { get; set; }
    }
}
