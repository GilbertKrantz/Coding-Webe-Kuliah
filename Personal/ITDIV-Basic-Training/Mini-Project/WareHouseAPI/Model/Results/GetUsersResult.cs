using System.ComponentModel.DataAnnotations;

namespace WareHouseAPI.Model.Results
{
    public class GetUsersResult
    {
        public Guid UserId { get; set; }

        public string Email { get; set; }

        public string Password { get; set; }

        public string Name { get; set; }
    }
}
