using System.ComponentModel.DataAnnotations;

namespace WareHouseAPI.Model.Requests
{
    public class UpdateUsersRequest
    {
        [Required]
        public Guid UserId { get; set; }

        [Required]
        public string Email { get; set; }

        [Required]
        public string Password { get; set; }

        [Required]
        public string Name { get; set; }
    }
}
