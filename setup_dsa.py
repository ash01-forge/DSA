#!/usr/bin/env python3
"""Restore DSA-I and DSA-II folders inside this GitHub repository."""
import hashlib
from pathlib import Path, PurePosixPath
import zipfile

ROOT = Path(__file__).resolve().parent
EXPECTED_SHA256 = "233028ab061f94241823e332d9c17ecf68aa044f4b7837067309075e39aae6f0"
EXPECTED_COUNT = 290
PREFIX = "DSA"
TEXT_TYPES = {".c", ".cpp", ".h", ".hpp", ".txt", ".md", ".json", ".py"}


def main():
    if not (ROOT / ".git").exists():
        raise RuntimeError("Run this file from the repository root in GitHub Codespaces.")
    archives = sorted(ROOT.glob("DSA*.zip"))
    archive = next((p for p in archives
                    if p.is_file() and p.stat().st_size < 40_000_000
                    and hashlib.sha256(p.read_bytes()).hexdigest() == EXPECTED_SHA256), None)
    if archive is None:
        raise RuntimeError("Upload the matching DSA.zip beside this setup file first.")
    files = []
    destinations = set()
    total_bytes = 0
    with zipfile.ZipFile(archive) as package:
        for item in package.infolist():
            if item.is_dir():
                continue
            path = PurePosixPath(item.filename)
            if path.is_absolute() or not path.parts or path.parts[0] != PREFIX:
                raise RuntimeError("Unexpected archive layout.")
            relative = PurePosixPath(*path.parts[1:])
            if not relative.parts or any(part in ("..", ".git") or ":" in part or "\\" in part for part in relative.parts):
                raise RuntimeError("Unexpected archive path.")
            if relative.as_posix().casefold() in destinations:
                raise RuntimeError("Duplicate archive destination.")
            destinations.add(relative.as_posix().casefold())
            destination = ROOT.joinpath(*relative.parts)
            if not destination.resolve().is_relative_to(ROOT):
                raise RuntimeError("Archive path is outside the repository.")
            for parent in destination.parents:
                if parent == ROOT:
                    break
                if parent.exists() and not parent.is_dir():
                    raise RuntimeError("A required folder is blocked by an existing file: " + str(relative))
            if item.file_size > 40_000_000:
                raise RuntimeError("Unexpected file size.")
            total_bytes += item.file_size
            if total_bytes > 100_000_000:
                raise RuntimeError("Unexpected package size.")
            data = package.read(item)
            if destination.exists():
                if not destination.is_file():
                    raise RuntimeError("A file destination is occupied by a folder: " + str(relative))
                previous = destination.read_bytes()
                if destination.suffix.lower() in TEXT_TYPES or destination.name in (".gitattributes", ".gitignore"):
                    same = previous.replace(b"\r\n", b"\n") == data.replace(b"\r\n", b"\n")
                else:
                    same = previous == data
                if not same:
                    raise RuntimeError("Existing file differs; nothing changed. Check: " + str(relative))
            files.append((destination, data))
    if len(files) != EXPECTED_COUNT:
        raise RuntimeError("The package does not contain the expected DSA source and study files.")
    for destination, data in files:
        destination.parent.mkdir(parents=True, exist_ok=True)
        destination.write_bytes(data)
    print("DONE: all " + str(EXPECTED_COUNT) + " DSA files are in their correct folders.")
    print("DSA-I and DSA-II are ready in one repository.")
    print("Next: git add .")
    print('Then: git commit -m "Add DSA-I and DSA-II coursework"')
    print("Then: git push")
    print("No commit, push, or remote changes were performed by this setup file.")


if __name__ == "__main__":
    try:
        main()
    except (OSError, RuntimeError, zipfile.BadZipFile) as error:
        raise SystemExit("Setup stopped: " + str(error))
