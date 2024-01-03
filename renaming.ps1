Get-ChildItem -Path "D:\CompetitiveProgramming" -Recurse | ForEach-Object {
    if (-not $_.PSIsContainer -and $_.Name -match '\._') {
        $newName = $_.Name -replace '\._', '_'
        Rename-Item -Path $_.FullName -NewName $newName -ErrorAction Stop
    }
}