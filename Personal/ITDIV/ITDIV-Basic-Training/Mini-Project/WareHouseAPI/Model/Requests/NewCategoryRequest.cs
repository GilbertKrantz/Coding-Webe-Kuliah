using System.ComponentModel.DataAnnotations;

namespace WareHouseAPI.Model.Requests
{
    public class NewCategoryRequest
    {
        [Required]
        public Guid UserId { get; set; }

        [Required]
        public string CategoryName { get; set; }
    }
}
