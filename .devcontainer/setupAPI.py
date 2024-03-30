import logging
import os
import tempfile
import zipfile
from getpass import getpass
from urllib.parse import urlparse

import requests


class SetupAPI:
    """A class to setup the API for the Bricsys-API repository."""

    ORG_NAME: str = 'Structura-Engineering'
    REPO_NAME: str = 'Bricsys-API'

    def __init__(self) -> None:
        """Initialize the class."""
        self.logger = self._logger()

        self._processor(
            self._fetcher(
                f'https://api.github.com/repos/{self.ORG_NAME}/{self.REPO_NAME}/contents',
                self._session(getpass('Please enter your access token: ')),
                f"""
                {self._validator(input('Specify API type: '), ['BRX', 'TX'])}/
                {self._validator(input('Specify API version: '), [''])}.zip
                """,
            ),
        )

    def _sanitizer(self, arg: str) -> str:
        """Sanitize the input.

        Args:
            arg (str): The argument to sanitize.
        """
        arg = arg.strip()
        if not arg.isalnum():
            self.logger.error(
                f"""Invalid Input: {arg}\n
                Input contains non-alphanumeric characters"""
            )
            arg = input('Please enter a valid input: ')
        return arg

    def _validator(self, arg: str, valid_arg: list[str]) -> str:
        """Validate the input.

        Args:
            arg (str): The argument to validate.
            valid_arg (list[str]): The valid arguments.
        """
        arg = self._sanitizer(arg)
        while arg not in valid_arg:
            self.logger.error(
                f'Invalid Input: {arg}\nValid Input: {valid_arg}'
            )
            arg = input('Please enter a valid input: ')
        return arg

    @staticmethod
    def _logger() -> logging.Logger:
        """Setup the logger."""
        logging.basicConfig(level=logging.INFO)
        return logging.getLogger(__name__)

    @staticmethod
    def _session(access_token: str) -> requests.Session:
        """Setup the session with headers.

        Args:
            access_token (str): The access token.
        """
        session = requests.Session()
        session.headers.update(
            {
                'Authorization': f'token {access_token}',
                'Accept': 'application/vnd.github.v3+json',
            }
        )
        return session

    def _fetcher(
        self,
        base_url: str,
        session: requests.Session,
        path: str = '',
    ) -> dict[str, str] | list[dict[str, str]]:
        """Fetch the contents of the repository.

        Args:
            base_url (str): The base URL.
            session (requests.Session): The session.
            path (str, optional): The path to the contents. Defaults to ''.
        """
        try:
            response = session.get(f'{base_url}/{path}')
            response.raise_for_status()
        except requests.RequestException as e:
            self.logger.error(f'Request failed: {e}')
            raise
        return response.json()

    def _processor(
        self,
        fetcher: dict[str, str] | list[dict[str, str]],
    ) -> None:
        """Process the contents of the repository.

        Args:
            fetcher (dict[str, str] | list[dict[str, str]]):
                The fetcher.
        """
        if isinstance(fetcher, dict):
            if fetcher.get('download_url'):
                self.logger.info(fetcher['download_url'])
                temp_path = self._downloader(fetcher['download_url'])
                self._installer(temp_path)

    def _downloader(self, url: str) -> str:
        """Download the API.

        Args:
            url (str): The URL of the API.
        """
        response = requests.get(url, stream=True)
        response.raise_for_status()

        temp_path = os.path.join(
            tempfile.gettempdir(), os.path.basename(urlparse(url).path)
        )

        with open(temp_path, 'wb') as file:
            for chunk in response.iter_content(chunk_size=8192):
                file.write(chunk)

        self.logger.info(f'Downloaded to: {temp_path}')
        return temp_path

    def _installer(
        self, temp_path: str, install_path: str = os.path.expanduser('~/lib')
    ) -> None:
        """Install the API.

        Args:
            temp_path (str): The temporary path.
            install_path (str, optional): The install path.
                Defaults to os.path.expanduser('~/lib').
        """
        new_dir_path = os.path.join(
            install_path, os.path.splitext(os.path.basename(temp_path))[0]
        )

        os.makedirs(new_dir_path, exist_ok=True)

        with zipfile.ZipFile(temp_path, 'r') as zip_ref:
            zip_ref.extractall(new_dir_path)

        self.logger.info(f'Unzipped files to: {new_dir_path}')

        os.remove(temp_path)

        self.logger.info(f'Removed the zip file: {temp_path}')


SetupAPI()
