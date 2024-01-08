List files and their size (GB)
```powershell
Get-ChildItem -Directory -ErrorAction SilentlyContinue | ForEach-Object {
    try {
        $folderPath = $_.FullName
        $folderSize = Get-ChildItem -Path $folderPath -Recurse -File -ErrorAction SilentlyContinue | Measure-Object -Property Length -Sum -ErrorAction SilentlyContinue
        if ($folderSize) {
            [PSCustomObject]@{
                Folder = $folderPath
                Size_GB = [math]::Round($folderSize.Sum / 1GB, 2)
            }
        }
    } catch {
        Write-Host "Error accessing folder: $_.FullName"
    }
}

```
