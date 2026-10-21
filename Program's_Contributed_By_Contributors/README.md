Thank you for this repo :)
Please contribute any program here.


// SUDOKU SOLVER //

class Solution {
public:
    bool issafe(vector<vector<char>> &bd, int i, int j, char ch)
{
    for (int k = 0; k < 9; k++)
    {
        if (bd[k][j] == ch)
            return 0;
    }
    for (int k = 0; k < 9; k++)
    {
        if (bd[i][k] == ch)
            return 0;
    }

    int r = i - i % 3;
    int c = j - j % 3;
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            if (bd[r + x][c + y] == ch)
                return 0;
        }
    }

    return 1;
}

bool sl(vector<vector<char>> &bd, int i, int j)
{
    if (i == 9)
        return 1;
    if (j == 9)
    {
        return sl(bd, i + 1, 0);
    }
    if (bd[i][j] != '.')
    {
        return sl(bd, i, j + 1);
    }

    for (char ch = '1'; ch <= '9'; ch++)
    {
        if (issafe(bd, i, j, ch))
        {
            bd[i][j] = ch;
            if (sl(bd, i, j + 1))
                return 1;
            bd[i][j] = '.';
        }
    }
    return 0;
}

void solveSudoku(vector<vector<char>> &bd)
{
    sl(bd, 0, 0);
}
};


// BINARY SEARCH IN PYTHON //

```python
def binary_search(arr: list[int], target: int) -> int:
    left = 0
    right = len(arr) - 1

    while left <= right:
        mid = (left + right) // 2

        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1


if __name__ == "__main__":
    numbers = [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]
    target_value = 23
    result = binary_search(numbers, target_value)
    print(f"Index: {result}")
```


// ROBLOX PLAYER DATASTORE //

```lua

local DataStoreService = game:GetService("DataStoreService")
local Players = game:GetService("Players")

local playerDataStore = DataStoreService:GetDataStore("MiJuegoDatos_v1")

local function getPlayerKey(player)
    return "Player_" .. player.UserId
end

local function onPlayerAdded(player)
    local success, savedData = pcall(function()
        return playerDataStore:GetAsync(getPlayerKey(player))
    end)

    if not success then
        warn("Could not load data for " .. player.Name .. ": " .. tostring(savedData))
        player:Kick("Your data could not be loaded. Please rejoin.")
        return
    end

    -- The player may have left while GetAsync was yielding.
    if player.Parent ~= Players then
        return
    end

    if type(savedData) ~= "table" then
        savedData = {}
    end

    local coinsValue = tonumber(savedData.Coins) or 0
    local levelValue = tonumber(savedData.Level) or 1

    local leaderstats = Instance.new("Folder")
    leaderstats.Name = "leaderstats"

    local coins = Instance.new("IntValue")
    coins.Name = "Coins"
    coins.Value = math.max(0, math.floor(coinsValue))
    coins.Parent = leaderstats

    local level = Instance.new("IntValue")
    level.Name = "Level"
    level.Value = math.max(1, math.floor(levelValue))
    level.Parent = leaderstats

    leaderstats.Parent = player
end

local function savePlayerData(player)
    local leaderstats = player:FindFirstChild("leaderstats")
    if not leaderstats then
        return
    end

    local coins = leaderstats:FindFirstChild("Coins")
    local level = leaderstats:FindFirstChild("Level")
    if not coins or not level then
        warn("Could not save incomplete data for " .. player.Name)
        return
    end

    local dataToSave = {
        Coins = coins.Value,
        Level = level.Value,
    }

    local success, err = pcall(function()
        playerDataStore:SetAsync(getPlayerKey(player), dataToSave)
    end)

    if not success then
        warn("Could not save data for " .. player.Name .. ": " .. tostring(err))
    end
end

Players.PlayerAdded:Connect(onPlayerAdded)
Players.PlayerRemoving:Connect(savePlayerData)

game:BindToClose(function()
    for _, player in ipairs(Players:GetPlayers()) do
        savePlayerData(player)
    end
end)
```
