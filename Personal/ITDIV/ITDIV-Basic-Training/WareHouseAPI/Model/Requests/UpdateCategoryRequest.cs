using System.ComponentModel.DataAnnotations;

namespace WareHouseAPI.Model.Requests
{
    public class UpdateCategoryRequest
    {
        [Required] public int CategoryId { get; set; }
        [Required] public string CategoryName { get; set; }
    }
}
